#include"shell.h"
using namespace std;

Shell::Shell(CmdParser& hdl)
	: cmdPsrHdl(&hdl) {}

void Shell::Run(){
	while(true){
		cout << "$ ";
		cmdPsrHdl->Parse(GetCommand())->Execute();
	}
}

string Shell::GetCommand(){
	string s;
	getline(cin, s);
	return s;
}

