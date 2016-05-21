#ifndef _FIELD_H_
#define _FIELD_H_

#include "Block.h"
#include "Cells.h"
#include "Direct.h"

using namespace std;

class Field {
private:
	Cells *cells;
	int cellX;
	int cellY;
public:
	Field();
	void show();
	void moveBlock(int ,Direct );
	bool checkField();
	~Field();
};

#endif
