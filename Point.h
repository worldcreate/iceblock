#ifndef _POINT_H_
#define _POINT_H_

class Point {
private:
	int x;
	int y;
public:
	void setX(int x){
		this->x = x;
	}
	int getX(){
		return this->x;
	}
	void setY(int y){
		this->y = y;
	}
	int getY(){
		return this->y;
	}
};

#endif
