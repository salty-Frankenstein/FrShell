#include"cmd_wc.h"
using namespace std;
using namespace DirUtils;

CmdWc::CmdWc(StrList opt, StrList para)
	: Command(opt, para) {}

bool CmdWc::Execute(){
	if(parameter.size() == 0){
		cout << "error" << endl;
		return false;
	}
	bool byteActive = false, wordActive = false, lineActive = false;
	if(option.size() == 0){
		byteActive = wordActive = lineActive = true;
	}
	else{
		for(auto i = option.begin(); i != option.end(); i++){
			if((*i) == "-c")byteActive = true;
			else if((*i) == "-w")wordActive = true;
			else if((*i) == "-l")lineActive = true;
			else{
				cout << "wc: invalid option -- '" << (*i) << "'" << endl;	
				return false;
			}
		}
	}
	
	int byteTotal = 0, wordTotal = 0, lineTotal = 0;
	for(auto i = parameter.begin(); i != parameter.end(); i++){
		int t;
		if(GetFileType(*i) == DU_DIRECTORY){
			cout << "wc: " + (*i) + ": Is a directory" << endl;
			cout << "0 0 0 " + (*i) << endl;
			continue;
		}
		ifstream fin((*i).c_str(), ios::binary);
		if(!fin.is_open()){
			cout << "wc: " + (*i) + ": No such file or directory" << endl;
			continue;
		}
		else{
			if(lineActive){
				t = CntLine(*i);
				lineTotal += t;
				cout << t << ' ';
			}
			if(wordActive){
				t = CntWord(*i);
				wordTotal += t;
				cout << t << ' ';
			}
			if(byteActive){
				t = CntByte(*i);
				byteTotal += t;
				cout << t << ' ';
			}
			cout << (*i) << endl;
		}
	}

	if(parameter.size() > 1){
		if(lineActive)cout << lineTotal << ' ';
		if(wordActive)cout << wordTotal << ' ';
		if(byteActive)cout << byteTotal << ' ';
		cout << "total" << endl;
	}
	return true;
}

int CmdWc::CntByte(const string& fname){
	ifstream fin(fname.c_str(), ios::binary);
	char buf;
	int cnt = 0;
	while(fin.read(&buf, sizeof(buf))){
		cnt++;
	}
	return cnt;
}

int CmdWc::CntWord(const string& fname){
	ifstream fin(fname.c_str(), ios::binary);
	string s;
	int cnt = 0;
	while(!fin.eof()){
		fin >> s;
		if(fin.fail())break;
		cnt++;
	}
	return cnt;
}

int CmdWc::CntLine(const string& fname){
	ifstream fin(fname.c_str(), ios::binary);
	string s;
	int cnt = 0;
	while(!fin.eof()){
		getline(fin, s);
		if(fin.fail())break;
		cnt++;
	}
	return cnt;
}

