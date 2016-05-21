#include "Cells.h"
#include "StringUtils.h"
#include "NumberUtils.h"

#include <iostream>

using namespace std;

Cells::Cells(int x,int y, FileReader& fileReader){
	cells.resize(y);
	for(int i = 0; i < cells.size() ; i++){
		cells[i].resize(x);
		string str = fileReader.readLine();
		vector<string> dividedString = StringUtils::split(str, ',');
		for(int j = 0; j < cells[i].size(); j++){
			int id = NumberUtils::convertStringToInt(dividedString[j]);
			
			FieldType fieldType = FieldType::of(id);
			if (fieldType.getId() == -1) {
				Block* block = new Block();
				cells[i][j] = new Cell(FieldType::PASS);
				cells[i][j]->setBlock(block);
			} else {
				cells[i][j] = new Cell(FieldType::of(id));
			}
		}
	}
}

Cell* Cells::getCell(int x,int y){
	return cells[y][x];
}

Point Cells::searchBlock(int blockId){
	Point p;
	for(int i = 0;i < cells.size(); i++){
		for(int j = 0; j < cells[i].size(); j++){
			if (cells[i][j]->getBlock() == NULL) {
				continue;
			}
			if(
				cells[i][j]->
				getBlock()->
				getId() ==
				blockId
			){
				p.setX(j);
				p.setY(i);
				return p;
			}
		}
	}
	p.setX(-1);
	p.setY(-1);
	return p;
}

Cells::~Cells(){
	for(int i = 0; i < cells.size(); i++){
		for(int j = 0; j < cells[i].size(); j++){
			delete cells[i][j];
		}
	}
}
