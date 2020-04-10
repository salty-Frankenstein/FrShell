#ifndef CMDPARSER_H
#define CMDPARSER_H

#include"command.h"
#include"cmd_cp.h"
#include<iostream>
#include<string>
#include<memory>

template<typename T>
using S_ptr = std::shared_ptr<T>;
using CommandSptr = S_ptr<Command>;		//smart pointer type of command objects

class CmdParser{
public:
	CommandSptr Parse(std::string str);
private:
		
};

#endif	//CMDPARSER_H

