#ifndef _FIELD_H_
#define _FIELD_H_

#include "Block.h"
#include "Cells.h"

using namespace std;

class Field {
private:
	Cells *cells;
public:
	Field();
	void show();
	void moveBlock(int ,int );
	~Field();
};

#endif
