#ifndef CMD_CP_H
#define CMD_CP_H
#include"command.h"
#include<iostream>

class CmdCp: public Command{
public:
	bool Execute();
};

#endif //CMD_CP_H

