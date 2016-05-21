#include "NumberUtils.h"

#include <sstream>

int NumberUtils::convertStringToInt(string line) {
	istringstream iss(line);
	int num;
	iss >> num;
	return num;
}
