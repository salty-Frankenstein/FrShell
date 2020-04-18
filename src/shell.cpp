#include"shell.h"
using namespace std;

Shell::Shell(){
	getcwd(path, PATH_MAX);
}

void Shell::Run(){
	while(true){
		cout << path;
		cout << "$ ";
		auto s = GetCommand();
		if(s == "exit")break;
		auto cmd = cmdPsr.Parse(s);
		if(cmd != nullptr)cmd->Execute();
	}
}

string Shell::GetCommand(){
	string s;
	getline(cin, s);
	return s;
}

