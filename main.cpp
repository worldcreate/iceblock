#include <iostream>

#include "UserService.h"
#include "IceblockRunner.h"

using namespace std;

int main(void){
	UserService *us = new UserService();
	IceblockRunner ir(us);
	ir.start();
}

