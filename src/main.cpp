#include<iostream>
#include"shell.h"
#include"cmdparser.h"
using namespace std;
int main(){
	Shell s;
	CmdParser cp;
	s.Run();
	cout<<"good"<<endl;
	return 0;
}
