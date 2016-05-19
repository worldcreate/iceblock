#include "Field.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

Field::Field(){
	cells = new Cells(4,4);
	cells->getCell(0, 0)->setBlock(new Block());
}

void Field::show(){
	for(int y = 0; y < 4; y++){
		for(int x = 0; x < 4; x++){
			string str;
			Block *block = cells->getCell(x,y)->getBlock();
			stringstream ss;
			ss << cells->getCell(x,y)->getFieldType();
			if(block != 0){
				ss << "(" << block->getId() << ")";
			}
			cout << setw(5)
				<< ss.str()
				<< ",";
		}
		cout<<endl;
	}
}

void Field::moveBlock(int blockId, int direct){
	Point p = cells->searchBlock(blockId);
}

Field::~Field(){
	delete cells;
}
