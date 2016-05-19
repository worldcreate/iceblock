#include "Cells.h"

Cells::Cells(int x,int y){
	cells.resize(y);
	for(int i = 0; i < cells.size() ; i++){
		cells[i].resize(x);
		for(int j = 0; j < cells[i].size(); j++){
			cells[i][j] = new Cell();
		}
	}
}

Cell* Cells::getCell(int x,int y){
	return cells[y][x];
}

Point Cells::searchBlock(int blockId){
	Point p;
	for(int i = 0;i < cells.size(); i++){
		for(int j = 0; i < cells[i].size(); i++){
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
}

Cells::~Cells(){
	for(int i = 0; i < cells.size(); i++){
		for(int j = 0; j < cells[i].size(); j++){
			delete cells[i][j];
		}
	}
}
