#include "FieldType.h"

FieldType FieldType::WALL = FieldType(0);
FieldType FieldType::PASS = FieldType(1);
FieldType FieldType::SWITCH = FieldType(2);
FieldType FieldType::BLOCK = FieldType(-1);

FieldType::FieldType(){}

FieldType::FieldType(int id) {
	this->id = id;
}

int FieldType::getId() const {
	return id;
}

vector<FieldType> FieldType::list() {
	vector<FieldType> list;
	list.push_back(WALL);
	list.push_back(PASS);
	list.push_back(SWITCH);

	return list;
}

FieldType FieldType::of(int id) {
	vector<FieldType> list = FieldType::list();
	for (int i = 0; i < list.size(); i++) {
		if (list[i].getId() == id) {
			return list[i];
		}
	}
	return -1;
}

bool FieldType::operator==(const FieldType& tar) const {
	return id == tar.getId();
}
