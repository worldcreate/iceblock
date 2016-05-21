#include "StringUtils.h"
#include <iostream>
#include <sstream>

using namespace std;

string StringUtils::replace(const char* message, ...) {
	char* origin;
	string text(message);

	int count = 0;
	for (int i = 0; ; i++) {
		int pos;
		stringstream ss;
		ss << "{" << i << "}";
		pos = text.find(ss.str());
		if (pos == string::npos) {
			break;
		} else {
			count++;
		}
	}

	va_list args;
	va_start(args, message);
	
	origin = va_arg(args, char*);
	for (int i = 0; i < count; i++) {
		stringstream ss;
		ss << "{" << i << "}";
		int start = text.find(ss.str());
		text.replace(start, 3, origin);

		origin = va_arg(args, char*);
	}
	va_end(args);

	return text;

}

string StringUtils::convertIntToString(int num) {
	stringstream ss;

	ss << num;

	return ss.str();
}

int StringUtils::convertStringToInt(string str) {
	istringstream iss(str);

	int num;
	iss >> num;
	return num;
}

vector<string> StringUtils::split(const string &line, char delim) {
	istringstream iss(line);
	string tmp;
	vector<string> res;
	while(getline(iss, tmp, delim)) res.push_back(tmp);
	return res;
}
