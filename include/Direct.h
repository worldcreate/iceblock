#ifndef _DIRECT_H_
#define _DIRECT_H_

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

private:
	Direct(int id, const char* name) {
		this->id = id;
		this->name = name;
	}

	int id;
	const char* name;
};

#endif
