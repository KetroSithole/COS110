#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream dataFile;

	cout << "Opening file.....\n";
	dataFile.open("demofile.txt", ios::out);		//Open for output
	dataFile << "Jones\n";
	dataFile << "Smith\n";
	dataFile<< "Joy\n";
	dataFile << "Kuda\n";
	dataFile.close();
	cout << "Done.\n";
	return 0;
}