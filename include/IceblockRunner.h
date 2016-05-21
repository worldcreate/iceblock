#ifndef _ICEBLOCKRUNNER_H_
#define _ICEBLOCKRUNNER_H_

#include "Service.h"
#include "Field.h"

class IceblockRunner{
private:
	Service *service;
	Field field;
	bool isShowMessage;
	int moveCount;
public:
	IceblockRunner(Service* service);
	void setMessageEnable();
	void setMessageDisable();
	void start();
	~IceblockRunner();
};

#endif
