#include "UserService.h"
#include "InputReader.h"
#include "StringUtils.h"

#include <string>
#include <sstream>
#include <vector>

using namespace std;

int UserService::getMoveBlockId(){
	string line = InputReader::readLine();
	int num = StringUtils::convertStringToInt(line);

	return num;
}

int UserService::getMoveDirection() {
	string line = InputReader::readLine();
	int num = StringUtils::convertStringToInt(line);

	return num;
}
