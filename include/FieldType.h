#ifndef _FIELDTYPE_H_
#define _FIELDTYPE_H_

#include <vector>

using namespace std;

class FieldType{
private:
	int id;
	FieldType(int id);
public:
	FieldType();
	static FieldType WALL;
	static FieldType PASS;
	static FieldType SWITCH;
	static FieldType BLOCK;

	bool operator==(const FieldType&)const;
	int getId() const;
	static vector<FieldType> list();
	static FieldType of(int);
};

#endif
