#ifndef SHELL_H
#define SHELL_H

#include<string>
#include<iostream>
#include"cmdparser.h"
#include"command.h"

class Shell{
public:
	void Run();
	std::string GetCommand();
	bool Execute(Command* msg);
private:
	CmdParser* cmdPsrHdl;
};

#endif	//SHELL_H
