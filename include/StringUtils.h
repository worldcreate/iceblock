#ifndef _STRINGUTILS_H_
#define _STRINGUTILS_H_

#include <string>
#include <stdarg.h>

using namespace std;

class StringUtils {
public:
	static string replace(const char* , ...);
	static string convertIntToString(int );
};

#endif
