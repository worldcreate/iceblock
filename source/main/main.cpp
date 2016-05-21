#include "UserService.h"
#include "IceblockRunner.h"
#include "FileReader.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(void){
	UserService *us = new UserService();
	IceblockRunner ir(us);
	ir.start();
}
