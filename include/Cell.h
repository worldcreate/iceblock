#ifndef _CELL_H_
#define _CELL_H_

#include "FieldType.h"
#include "Block.h"

#define NULL 0

class Cell{
private:
	FieldType fieldType;
	Block* block;
public:
	Cell();
	Cell(FieldType fieldType);
	Block* getBlock();
	void setBlock(Block* b);
	FieldType getFieldType();
	void setFieldType(FieldType fieldtype);
	~Cell();
};

#endif
