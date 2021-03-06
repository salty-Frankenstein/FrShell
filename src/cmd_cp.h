#ifndef CMD_CP_H
#define CMD_CP_H
#include"command.h"
#include"directory.h"
#include<iostream>
#include<fstream>

class CmdCp: public Command{
public:
	CmdCp(StrList opt, StrList para);
	bool Execute();
private:
	bool CopyFile(std::string from, std::string to);
	bool CopyDirectory(std::string from, std::string to);//absolute path only
};

#endif //!CMD_CP_H

