#include"cmd_cp.h"
using namespace std;

CmdCp::CmdCp(StrList opt, StrList para)
	: Command(opt, para){}

bool CmdCp::Execute(){
	if(parameter.size() < 2){	//TODO: warnings
		cout << "error"<<endl;
		return false;
	}
	auto i = parameter.begin();
	string fileFrom, fileTo;	//file name
	fileFrom = (*i);
	i++;
	fileTo = (*i);
	//TODO
	if(fileFrom == fileTo){
		cout << "cp: '" << fileFrom << "' and '" << fileTo << "' ";
		return false;
	}
	/* input file */
	ifstream fin(fileFrom.c_str(), ios::binary);
	if(!fin.is_open()){
		cout << "cp: cannot stat '" << fileFrom << "': No such file or directory" << endl;
		return false;
	}
	/* output file */
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

