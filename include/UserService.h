#ifndef _USERSERVICE_H_
#define _USERSERVICE_H_

#include "Service.h"

class UserService : public Service {
private:

public:
	virtual int getMoveBlockId();
	virtual int getMoveDirection();
};

#endif
