#ifndef DIRECTORY_H
#define DIRECTORY_H

#include<string>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<limits.h>
#include<unistd.h>
#include<cstdlib>
#include<list>

typedef std::list<std::string> StrList;

namespace DirUtils{
	enum FileType { DU_FILE, DU_DIRECTORY, DU_OTHER, DU_NULL };
	bool AbsPath(const std::string& pathIn, std::string& pathOut);
	bool IsSameDir(const std::string& path1,const std::string& path2);
	bool IsExist(const std::string& path);
	FileType GetFileType(const std::string& path);
	StrList GetDirFiles(const std::string& path);
	void MakeDirectory(const std::string& path);
	std::string GetLastPath(const std::string& path);
}


#endif //!DIRECTORY_H

