#ifndef CMD_CAT_H
#define CMD_CAT_H

#include"command.h"
#include<iostream>
#include<fstream>

class CmdCat: public Command{
public:
	CmdCat(StrList opt, StrList para);
	bool Execute();
};

#endif //!CMD_CAT_H

