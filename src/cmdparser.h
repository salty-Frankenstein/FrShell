#ifndef CMDPARSER_H
#define CMDPARSER_H

#include"command.h"
#include<iostream>
#include<sstream>
#include<string>
#include<memory>

template<typename T>
using S_ptr = std::shared_ptr<T>;
using CommandSptr = S_ptr<Command>;		//smart pointer type of command objects


class CmdParser{
public:
	CommandSptr Parse(std::string str);
};


#endif	//!CMDPARSER_H

