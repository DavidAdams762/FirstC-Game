#include "Log.h"

Log::Log() {
}

void Log::deleteFile() {
	ifstream ifile("log.log");

	if (ifile) {
		remove("log.log");
	}
}

void Log::writeLog(string errorType, string str) {
	ofstream myfile;
	time_t timev;
	myfile.open ("log.log", std::ios::app);
	myfile << time(&timev);
	myfile << " << " << errorType << " << ";
	myfile << str << endl;
	myfile.close();
}