#ifndef COMMAND_H
#define COMMAND_H

#include<list>
#include<string>
#include<map>

typedef std::list<std::string> StrList;

enum CommandType { CMD_INVA, CMD_CP, CMD_CMP, CMD_WC, CMD_CAT, CMD_MAN , CMD_SH };	//CMD_INVA(int 0) is for invalid commands

extern std::map<std::string, CommandType> commandMap;

class Command{
public:
	Command(StrList opt, StrList para);
	virtual bool Execute() = 0;
protected:
	StrList option;
	StrList parameter;
};

#endif	//!COMMAND_H

