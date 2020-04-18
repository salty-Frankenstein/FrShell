#include"cmd_man.h"
using namespace std;

CmdMan::CmdMan(StrList opt, StrList para)
	: Command(opt, para) {}

bool CmdMan::Execute(){
	if(option.size() != 0){
		cout << "man: invalid option" << endl;
		return false;
	}
	string path("manual/");
	switch(commandMap[parameter.front()]){
	case CMD_INVA:
		cout << "No manual entry for " << parameter.front() << endl;
		return false;
	case CMD_CP:
		path += "cp";
		break;
	case CMD_CMP:
		path += "cmp";
		break;
	case CMD_WC:
		path += "wc";
		break;
	case CMD_CAT:
		path += "cat";
		break;
	case CMD_MAN:
		path += "man";
		break;
	case CMD_SH:
		path += "sh";
		break;
	}
	ifstream fin(path);
	while(!fin.eof()){
		string s;
		getline(fin, s);
		cout << s << endl;
	}

	return true;
}

