#ifndef _CELL_H_
#define _CELL_H_

#include "FieldType.h"
#include "Block.h"

class Cell{
private:
	FieldType fieldType;
	Block* block;
public:
	Cell(){
		block = 0;
	};
	Block* getBlock(){
		return block;
	};
	void setBlock(Block* b){
		block = b;
	};
	FieldType getFieldType(){
		return fieldType;
	};
	void setFieldType(FieldType fieldtype){
		fieldType = fieldtype;
	};
	~Cell(){
		delete block;
	}
};

#endif
