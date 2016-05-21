#include "Cell.h"

Cell::Cell() {
	block = NULL;
}

Cell::Cell(FieldType fieldType) {
	block = NULL;
	this->fieldType = fieldType;
}

Block* Cell::getBlock() {
	return block;
}

void Cell::setBlock(Block* b) {
	block = b;
}

FieldType Cell::getFieldType() {
	return fieldType;
}

void Cell::setFieldType(FieldType fieldType) {
	this->fieldType = fieldType;
}

Cell::~Cell() {
	delete block;
}
