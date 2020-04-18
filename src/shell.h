#ifndef SHELL_H
#define SHELL_H

#include<string>
#include<iostream>
#include<unistd.h>
#include<limits.h>
#include"cmdparser.h"
#include"command.h"

class Shell{
public:
	Shell(CmdParser& hdl);
	void Run();
	std::string GetCommand();
private:
	CmdParser* cmdPsrHdl;
	char path[PATH_MAX];
};

#endif	//!SHELL_H

