#include<iostream>
#include"shell.h"
#include"cmdparser.h"
using namespace std;
int main(){
	CmdParser cp;
	Shell s(cp);
	s.Run();
	return 0;
}
