#ifndef CMD_CP_H
#define CMD_CP_H
#include"command.h"
#include<iostream>
#include<fstream>

class CmdCp: public Command{
public:
	CmdCp(StrList opt, StrList para);
	bool Execute();
};

#endif //!CMD_CP_H

