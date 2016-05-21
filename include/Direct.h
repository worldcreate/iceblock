#ifndef _DIRECT_H_
#define _DIRECT_H_

#include <vector>

using namespace std;

class Direct {
public:
	static Direct LEFT;
	static Direct RIGHT;
	static Direct UP;
	static Direct DOWN;

	int getId() {
		return id;
	}

	const char* getName() {
		return name;
	}

	int getMoveX() {
		return moveX;
	}

	int getMoveY() {
		return moveY;
	}

	static vector<Direct> list();

	static Direct& of(int);
private:
	Direct(int id, const char* name, int moveX, int moveY) {
		this->id = id;
		this->name = name;
		this->moveX = moveX;
		this->moveY = moveY;
	}

	int id;
	const char* name;
	int moveX;
	int moveY;
};

#endif
