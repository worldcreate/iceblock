#include "FileReader.h"

#include <iostream>

using namespace std;

FileReader::FileReader(const char* fileName) {
	ifs.open(fileName, ios::in);
	if (ifs.fail()){
		cerr << "file read error" << endl;
	}
}

string FileReader::readLine() {
	if (ifs.eof())
		return string("");

	string line;
	getline(ifs, line);

	return line;
}
