#include "IceblockRunner.h"
#include "Message.h"
#include "Block.h"
#include "StringUtils.h"
#include <iostream>
#include <sstream>

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

	int blockId = service -> getMoveBlockId();

	if (isShowMessage) {
		cout << Message::SHOW_SELECT_MOVE_DIRECT_MESSAGE << endl;
		cout << 
			StringUtils::replace(Message::SHOW_DIRECT_INDEX_MESSAGE,
				StringUtils::convertIntToString(Direct::LEFT.getId()).c_str(), Direct::LEFT.getName(),
				StringUtils::convertIntToString(Direct::RIGHT.getId()).c_str(), Direct::RIGHT.getName(),
				StringUtils::convertIntToString(Direct::UP.getId()).c_str(), Direct::UP.getName(),
				StringUtils::convertIntToString(Direct::DOWN.getId()).c_str(), Direct::DOWN.getName())
			<< endl;
	}
	Direct moveDirection = service -> getMoveDirection();

	field.moveBlock(blockId,moveDirection);
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
