#include"cmd_cmp.h"
using namespace std;
using namespace DirUtils;

CmdCmp::CmdCmp(StrList opt, StrList para)
	: Command(opt, para){}

bool CmdCmp::Execute(){
	if(option.size() != 0){	
		cout << "cmp: invalid option -- '" << option.front() << "'" << endl;
		cout << "Try 'cmp -- help' for more information." << endl;
		return false;
	}
	if(parameter.size() < 2){
		cout << "error" << endl;
		return false;
	}
	auto i = parameter.begin();
	string fileName1, fileName2;
	fileName1 = (*i);
	i++;
	fileName2 = (*i);

	if(GetFileType(fileName1) == DU_DIRECTORY){
		cout << "cmp: " << fileName1 << ": Is a directory" << endl;
		return false;
	}
	if(GetFileType(fileName2) == DU_DIRECTORY){
		cout << "cmp: " << fileName2 << ": Is a directory" << endl;
		return false;
	}
	/* input file */
	ifstream file1(fileName1.c_str(), ios::binary),
		file2(fileName2.c_str(), ios::binary);
	if(!file1.is_open()){
		cout << "cmp: " << fileName1 << ": No such file or directory" << endl;
		return false;
	}
	if(!file2.is_open()){
		cout << "cmp: " << fileName2 << ": No such file or directory" << endl;
		return false;
	}
	/* comparing */
	char t1, t2;
	int cntLine = 1, cntByte = 0;

	while(!file1.eof() && !file2.eof()){
		cntByte++;
		file1.read(&t1, sizeof(t1));
		file2.read(&t2, sizeof(t2));
		if(file1.fail() && file2.fail())return true;
		if(file1.fail()){
			cout << "cmp: EOF on " << fileName1 << endl;
			return false;
		}
		if(file2.fail()){
			cout << "cmp: EOF on " << fileName2 << endl;
			return false;
		}
		if(t1 != t2){
			cout << fileName1 << ' ' << fileName2 << " differ: ";
			cout << "byte " << cntByte << ", ";
			cout << "line " << cntLine << endl;
			return 0;
		}
		if(t1 == '\n')cntLine++;
	}

	return true;
}

