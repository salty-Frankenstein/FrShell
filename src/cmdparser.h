#ifndef CMDPARSER_H
#define CMDPARSER_H

#include"command.h"
#include"cmd_cp.h"
#include<iostream>
#include<sstream>
#include<string>
#include<memory>
#include<map>

template<typename T>
using S_ptr = std::shared_ptr<T>;
using CommandSptr = S_ptr<Command>;		//smart pointer type of command objects

enum CommandType { CMD_INVA, CMD_CP, CMD_CMP, CMD_WC, CMD_CAT, CMD_MAN };	//CMD_INVA(int 0) is for invalid commands

class CmdParser{
public:
	CommandSptr Parse(std::string str);
private:
	static std::map<std::string, CommandType> commandMap;
};


#endif	//CMDPARSER_H

