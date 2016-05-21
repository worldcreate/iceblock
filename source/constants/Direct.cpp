#include "Direct.h"

Direct Direct::LEFT = Direct(0, "LEFT", -1, 0);
Direct Direct::RIGHT = Direct(1, "RIGHT", 1, 0);
Direct Direct::UP = Direct(2, "UP", 0, -1);
Direct Direct::DOWN = Direct(3, "DOWN", 0, 1);

vector<Direct> Direct::list() {
	vector<Direct> list;
	list.push_back(LEFT);
	list.push_back(RIGHT);
	list.push_back(UP);
	list.push_back(DOWN);

	return list;
}

Direct& Direct::of(int id) {
	vector<Direct> list = Direct::list();
	for (int i = 0; i < list.size(); i++) {
		if (list[i].getId() == id) {
			return list[i];
		}
	}
}

