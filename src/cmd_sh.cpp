#include"cmd_sh.h"
using namespace std;

CmdSh::CmdSh(StrList opt, StrList para)
	: Command(opt, para) {}

bool CmdSh::Execute(){
	if(option.size() != 0){
		cout << "sh: invalid option" << endl;
		return false;
	}
	
	auto fileName = parameter.front();
	ifstream fin(fileName);
	if(!fin.is_open()){
		cout << "sh: cannot stat '" << fileName << "': No such fileName or directory" << endl;
	}

	while(!fin.eof()){
		string s;
		getline(fin, s);
		if(s == "exit")break;
		auto cmd = cmdPsr.Parse(s);
		if(cmd != nullptr)cmd->Execute();
	}

	return true;
}

