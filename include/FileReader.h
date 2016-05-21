#ifndef _FILEREADER_H_
#define _FILEREADER_H_

#include <string>
#include <fstream>

using namespace std;

class FileReader {
public:
	FileReader(const char*);
	string readLine();
private:
	ifstream ifs;
};


#endif
