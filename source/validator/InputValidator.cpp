#include "InputValidator.h"
#include "Block.h"
#include "Direct.h"

#include <vector>

using namespace std;

bool InputValidator::checkBlockNumber(int num) {
	return 0 <= num && num <= Block::count;
}

bool InputValidator::checkDirectNumber(int num) {
	vector<Direct> list = Direct::list();
	for (int i = 0; i < list.size() ; i++) {
		if (list[i].getId() == num) {
			return true;
		}
	}
	return false;
}
