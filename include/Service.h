#ifndef _SERVICE_H_
#define _SERVICE_H_

#include "Direct.h"

class Service {
private:

public:
	virtual int getMoveBlockId();
	virtual int getMoveDirection();
};

#endif
