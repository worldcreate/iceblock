#include "IceblockRunner.h"
#include "Message.h"
#include "Block.h"
#include "StringUtils.h"
#include "InputValidator.h"
#include <iostream>
#include <sstream>

using namespace std;

IceblockRunner::IceblockRunner(Service* service){
	this->service = service;
	isShowMessage = true;
	moveCount = 0;
}

void IceblockRunner::start(){
	while (true) {

		if (isShowMessage) {
			cout << Message::SHOW_NOW_STATUS_MESSAGE << endl;
		}
		field.show();

		if (isShowMessage) {
			cout << Message::SHOW_SELECT_MOVE_BLOCK_MESSAGE << endl;
		}

		int blockId = service -> getMoveBlockId();
		if (!InputValidator::checkBlockNumber(blockId)) {
			cout << Message::ERROR_BLOCK_ID << endl;
			continue;
		}

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
		int moveDirection = service -> getMoveDirection();
		if (!InputValidator::checkDirectNumber(moveDirection)) {
			cout << Message::ERROR_DIRECT_ID << endl;
			continue;
		}
		Direct direction = Direct::of(moveDirection);

		field.moveBlock(blockId,direction);
		moveCount++;

		if (field.checkField()) {
			cout << 
				StringUtils::replace(
					Message::COMPLETE_MESSAGE,
					StringUtils::convertIntToString(moveCount).c_str()
				) << endl;
			break;
		}

	}
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
