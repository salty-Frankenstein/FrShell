#ifndef SHELL_H
#define SHELL_H

#include<string>
#include<iostream>
#include"cmdparser.h"
#include"command.h"

class Shell{
public:
	Shell(CmdParser& hdl);
	void Run();
	std::string GetCommand();
	//bool Execute(CommandSptr msg);
private:
	CmdParser* cmdPsrHdl;
};

#endif	//SHELL_H

