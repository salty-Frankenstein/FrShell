#ifndef CMDPARSER_H
#define CMDPARSER_H

#include"command.h"
#include<iostream>
#include<string>

class CmdParser{
public:
	Command* Parse(std::string str);
private:
		
};

#endif	//CMDPARSER_H

