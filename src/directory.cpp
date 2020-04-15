#include"directory.h"
using namespace std;

bool DirUtils::AbsPath(const string& pathIn, string& pathOut){
	char absPath[PATH_MAX];
	if(realpath(pathIn.c_str(), absPath)){
		pathOut = absPath;
		return true;
	}
	return false;
}

bool DirUtils::IsSameDir(const string& p1, const string& p2){
	string s1, s2;
	AbsPath(p1, s1);
	AbsPath(p2, s2);
	return s1 == s2;
}

DirUtils::FileType DirUtils::GetFileType(const string& p){
	struct stat st;
	int res = stat(p.c_str(), &st);
	if(res != 0){
		return DU_NULL;
	}
	if(S_ISDIR(st.st_mode) != 0)
		return DU_DIRECTORY;
	if(S_ISREG(st.st_mode) != 0)
		return DU_FILE;
	return DU_OTHER;
}

StrList DirUtils::GetDirFiles(const string& p){
	StrList sl;
	DIR* dir = opendir(p.c_str());
	struct dirent *dirp = nullptr;
	while((dirp = readdir(dir)) != NULL){
		sl.push_back(string(dirp->d_name));
	}
	return sl;
}

