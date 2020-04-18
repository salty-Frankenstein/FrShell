#include"command.h"
using namespace std;

map<string, CommandType> commandMap = {
	{"cp", CMD_CP},
	{"cmp", CMD_CMP},
	{"wc", CMD_WC},
	{"cat", CMD_CAT},
	{"man", CMD_MAN},
	{"sh", CMD_SH}
};

Command::Command(StrList opt, StrList para)
	: option(opt), parameter(para){}

