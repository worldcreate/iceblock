#ifndef _STRINGUTILS_H_
#define _STRINGUTILS_H_

#include <string>
#include <stdarg.h>
#include <vector>

using namespace std;

class StringUtils {
public:
	static string replace(const char* , ...);
	static string convertIntToString(int );
	static vector<string> split(const string&,char);
	static int convertStringToInt(string);
};

#endif
