#ifndef CMD_MAN_H
#define CMD_MAN_H

#include"command.h"
#include<iostream>
#include<fstream>
#include<string>

class CmdMan: public Command{
public:
	CmdMan(StrList opt, StrList para);
	bool Execute();
};

#endif //!CMD_MAN_H

