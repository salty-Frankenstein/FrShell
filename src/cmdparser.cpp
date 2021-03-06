#include"cmdparser.h"
#include"all_commands.h"
using namespace std;

CommandSptr CmdParser::Parse(string str){
	if(str.empty())return nullptr;
	stringstream ss(str);
	string cmd;
	ss >> cmd;

	StrList opt;
	StrList para;
	while(!ss.eof()){
		string t;
		if(ss.eof())break;
		ss >> t;
		if(t[0] == '-')
			opt.push_back(t);
		else para.push_back(t);
	}

	switch(commandMap[cmd]){
	case CMD_INVA:
		cout << cmd << ": command not found" << endl;
		return nullptr;
	case CMD_CP:
		return CommandSptr(make_shared<CmdCp>(opt, para));
	case CMD_CMP:
		return CommandSptr(make_shared<CmdCmp>(opt, para));
	case CMD_WC:
		return CommandSptr(make_shared<CmdWc>(opt, para));
	case CMD_CAT:
		return CommandSptr(make_shared<CmdCat>(opt, para));
	case CMD_MAN:
		return CommandSptr(make_shared<CmdMan>(opt, para));
	case CMD_SH:
		return CommandSptr(make_shared<CmdSh>(opt, para));
	}
	return nullptr;
}

