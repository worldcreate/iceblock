#ifndef _CELLS_H_
#define _CELLS_H_

#include "FieldType.h"
#include "Cell.h"
#include "FileReader.h"

#include <vector>

using namespace std;

class Cells{
private:
	vector<vector<Cell*> > cells;
public:
	Cells(int, int, FileReader&);
	Cell* getCell(int, int);
	Point searchBlock(int);
	~Cells();
};

#endif
