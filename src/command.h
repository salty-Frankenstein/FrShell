#ifndef COMMAND_H
#define COMMAND_H

#include<list>
#include<string>

typedef std::list<std::string> StrList;

class Command{
public:
	Command(StrList opt, StrList para);
	virtual bool Execute() = 0;
protected:
	StrList option;
	StrList parameter;
};

#endif	//COMMAND_H

