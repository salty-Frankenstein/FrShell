#include"cmdparser.h"
using namespace std;

CommandSptr CmdParser::Parse(string str){
	//cout<<"cmd parse"<<endl;
	stringstream ss(str);
	string cmd;
	ss >> cmd;
	//
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
	
	cout << "now parsing:";
	cout << "(cmd " << cmd << ") ";
	cout << "(opt ";
	for(auto i = opt.begin(); i != opt.end(); i++)
		cout << "(" << (*i) << ')';
	cout << ") ";

	cout << "(para ";
	for(auto i = para.begin(); i != para.end(); i++)
		cout << "(file " << (*i) << ')';
	cout<<")\n";

	return CommandSptr(make_shared<CmdCp>(opt, para));
	return nullptr;
}

