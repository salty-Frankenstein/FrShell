#include"cmd_cat.h"
using namespace std;

CmdCat::CmdCat(StrList opt, StrList para)
	: Command(opt, para) {}

bool CmdCat::Execute(){
	if(option.size() != 0){	//TODO: change error info into function
		cout << "cat: invalid option -- '" << option.front() << "'" << endl;
		cout << "Try 'cat -- help' for more information." << endl;
		return false;
	}
	
	if(parameter.size() <= 0){	//TODO
		//cout << "error" << endl;
		return false;
	}

	for(auto i = parameter.begin(); i != parameter.end(); i++){
		ifstream fin((*i).c_str(), ios::binary);
		if(!fin.is_open()){
			cout << "cat: " << (*i) << ": No such file or directory" << endl;
			continue;
		}
		char t;
		while(fin.read(&t, sizeof(t))){
			cout << t;
		}
		fin.close();
	}

	return true;
}


