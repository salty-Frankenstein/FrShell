#include"cmd_cp.h"
using namespace std;
using namespace DirUtils;

CmdCp::CmdCp(StrList opt, StrList para)
	: Command(opt, para){}

bool CmdCp::Execute(){
	if(parameter.size() < 2){	//TODO: warnings
		cout << "error"<<endl;
		return false;
	}
	
	bool rActive = false;
	if(option.size() == 1){
		if(option.front() == "-r")rActive = true;
		else{
			cout << "cp: invalid option -- '" << option.front() << "'" << endl;
			return false;
		}
	}
	else if(option.size() == 0);
	else{
		cout << "cp: invalid option" << endl;
		return false;
	}

	auto i = parameter.begin();
	string fileFrom, fileTo;	//file name
	fileFrom = (*i);
	i++;
	fileTo = (*i);
	
	if(!IsExist(fileFrom)){
		cout << "cp: cannot stat '" << fileFrom << "': No such file or directory" << endl;
		return false;
	}

	/* path is a directory */
	if(GetFileType(fileFrom) == DU_DIRECTORY){
		if(rActive){
			/* copy a directory to a file */
			if(GetFileType(fileTo) == DU_FILE){
				cout << "cp: cannot overwrite non-directory '" << fileTo << "' with directory " << fileFrom << endl;
				return false;
			}
			else{
				string absFrom, absTo;
				AbsPath(fileFrom, absFrom);
				if(AbsPath(fileTo, absTo)){
					absTo += '/' + GetLastPath(absFrom);//the path copy to
				}
				else{
					MakeDirectory(fileTo);
					AbsPath(fileTo, absTo);
				}
				
				/* same directory */
				if(absFrom == absTo){
					cout << "cp: '" << fileFrom << "' and '" << fileTo + '/' + GetLastPath(absFrom) << "' are the same file" << endl;
					return false;
				}
				else{
					MakeDirectory(absTo);
					return CopyDirectory(absFrom, absTo);
				}
			}
		}
		else{
			cout << "cp: omitting directory '" << fileFrom << "'" << endl;
			return false;
		}
	}

	/* path is a file */
	return CopyFile(fileFrom, fileTo);
}

bool CmdCp::CopyDirectory(string fileFrom, string fileTo){
	auto l = GetDirFiles(fileFrom);
	for(auto i = l.begin(); i != l.end(); i++){
		auto nextFileFrom = fileFrom + '/' + *i;
		auto nextFileTo = fileTo + '/' + *i;
		if(GetFileType(fileFrom + '/' + *i) == DU_FILE){
			CopyFile(nextFileFrom, nextFileTo);
		}
		else{	/* recursion */
			if(*i == "." || *i == "..")continue;
			else{
				MakeDirectory(nextFileTo);
				CopyDirectory(nextFileFrom, nextFileTo);
			}
		}
	}
	return true;
}

bool CmdCp::CopyFile(string fileFrom, string fileTo){
	if(IsSameDir(fileFrom, fileTo)){
		cout << "cp: '" << fileFrom << "' and '" << fileTo << "' are the same file" << endl;
		return false;
	}
	/* input file */
	ifstream fin(fileFrom.c_str(), ios::binary);
	if(!fin.is_open()){
		cout << "cp: cannot stat '" << fileFrom << "': No such file or directory" << endl;
		return false;
	}
	/* output file */
	if(GetFileType(fileTo) == DU_DIRECTORY){
		fileTo = fileTo + "/" + fileFrom;
	}
	
	ofstream fout(fileTo.c_str(), ios::binary);
	if(!fout.is_open()){
		cout << "cp: cannot regular file '" << fileTo << "': No such file or directory" << endl;
		return false;
	}
	/* copying */
	char buf;
	while(fin.read(&buf, sizeof(buf))){
		fout.write(&buf, sizeof(buf));
	}
	fin.close();
	fout.close();
	//cout << "Executing" << endl;
	return true;
}

