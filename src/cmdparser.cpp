#include"cmdparser.h"
using namespace std;

CommandSptr CmdParser::Parse(string str){
	cout<<"cmd parse"<<endl;
	return CommandSptr(make_shared<CmdCp>());
	return nullptr;
}

