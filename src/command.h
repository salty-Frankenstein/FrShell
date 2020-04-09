#ifndef COMMAND_H
#define COMMAND_H

#include<list>
#include<string>

class Command{
public:
	virtual bool Execute() = 0;
protected:
	std::list<std::string> option;
	std::list<std::string> parameter;
};

#endif	//COMMAND_H

