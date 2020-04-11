#ifndef CMD_CMP_H
#define CMD_CMP_H

#include"command.h"
#include<iostream>
#include<fstream>

class CmdCmp: public Command{
public:
	CmdCmp(StrList opt, StrList para);
	bool Execute();
};

#endif //!CMD_CMP_H

