#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "Point.h"

class Block {
private:
	int id;
	Point point;
public:
	Block(){};
	void setId(int id){
		this->id = id;
	}
	int getId(){
		return this->id;
	}
	void setPoint(Point p){
		this->point = p;
	}
	Point getPoint(){
		return this->point;
	}
};

#endif
