#ifndef CMD_SH_H
#define CMD_SH_H

#include"command.h"
#include"cmdparser.h"
#include<iostream>
#include<fstream>

class CmdSh: public Command{
public:
	CmdSh(StrList opt, StrList para);
	bool Execute();
private:
	CmdParser cmdPsr;	
};

#endif //!CMD_SH_H

