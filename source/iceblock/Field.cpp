#include "Field.h"
#include "FieldType.h"
#include "FileReader.h"
#include "StringUtils.h"
#include "NumberUtils.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

Field::Field(){
	FileReader fileReader("resource/map.dat");
	string str = fileReader.readLine();
	vector<string> dividedString = StringUtils::split(str,',');
	cellX = NumberUtils::convertStringToInt(dividedString[0]);
	cellY = NumberUtils::convertStringToInt(dividedString[1]);

	cells = new Cells(cellX, cellY, fileReader);
}

void Field::show(){
	for(int y = 0; y < cellY; y++){
		for(int x = 0; x < cellX; x++){
			string str;
			Block *block = cells->getCell(x,y)->getBlock();
			stringstream ss;
			ss << cells->getCell(x,y)->getFieldType().getId();
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

void Field::moveBlock(int blockId, Direct direct){
	Point p = cells->searchBlock(blockId);

	int nowX = p.getX();
	int nowY = p.getY();

	while (true) {
	
		Cell* cell = cells->getCell(nowX, nowY);
		Block* block = cell->getBlock();

		int nextX = nowX + direct.getMoveX();
		int nextY = nowY + direct.getMoveY();

		if (nextX < 0 || nextY < 0 ||
			nextX >= cellX || nextY >= cellY) {
			break;
		}
		Cell* nextCell = cells->getCell(nowX + direct.getMoveX(), nowY + direct.getMoveY());

		if (nextCell->getFieldType() == FieldType::WALL) {
			break;
		}

		cell->setBlock(NULL);
		nextCell->setBlock(block);

		nowX = nextX;
		nowY = nextY;
	}
}

bool Field::checkField() {
	for (int i = 0; i < cellY; i++) {
		for (int j = 0; j < cellX ; j++) {
			Cell* cell = cells->getCell(j,i);
			FieldType fieldType = cell->getFieldType();
			if (fieldType.getId() == FieldType::SWITCH.getId()) {
				if (cell->getBlock() == NULL) {
					return false;
				}
			}
		}
	}
	return true;
}

Field::~Field(){
	delete cells;
}
