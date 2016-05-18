#include "IceblockRunner.h"
#include "Message.h"
#include "Block.h"
#include <iostream>

using namespace std;

IceblockRunner::IceblockRunner(Service* service){
	this->service = service;
	isShowMessage = true;
}

void IceblockRunner::start(){
	if (isShowMessage) {
		cout << Message::SHOW_NOW_STATUS_MESSAGE << endl;
	}
	field.show();

	if (isShowMessage) {
		cout << Message::SHOW_SELECT_MOVE_BLOCK_MESSAGE << endl;
	}

	cout << service -> getMoveBlockId() << endl;
}

void IceblockRunner::setMessageEnable(){
	isShowMessage = true;
}

void IceblockRunner::setMessageDisable(){
	isShowMessage = false;
}

IceblockRunner::~IceblockRunner(){
	delete service;
}
