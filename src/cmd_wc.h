#ifndef CMD_WC_H
#define CMD_WC_H

#include"command.h"
#include"directory.h"
#include<iostream>
#include<fstream>
#include<string>

class CmdWc: public Command{
public:
	CmdWc(StrList opt, StrList para);
	bool Execute();
private:
	int CntByte(const std::string& fname);
	int CntWord(const std::string& fname);
	int CntLine(const std::string& fname);
};

#endif //!CMD_WC_H

