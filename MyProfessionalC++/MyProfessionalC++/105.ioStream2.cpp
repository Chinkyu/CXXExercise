#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void file_stream() {
	ofstream outFile("test.txt", ios_base::trunc);
	if (!outFile.good()) {
		cerr << "Error whild opening output file!" << endl;
		return;
	}
	outFile << "There were " << "file" << " arguments to this program. " << endl;
	outFile << "They are: " << endl;
	for (int i = 0; i < 10; i++) {
		outFile << i << " " << endl;
	}
}

// bidirectional stream team 
bool changeNumberForId(const string& inFileName, int inId, const string& inNewNumber) {
	fstream ioData(inFileName.c_str());
	if (!ioData) {
		cerr << "Error while opening file " << inFileName << endl;
		return false;
	}

	// Loop until the end of file
	while (ioData.good()) {
		int id;
		string number;
		//Read the next Id
		ioData >> id;
		// Check to see if the current record is the one being changed
		if (id == inId) {
			// Seek the write position to the current read position
			ioData.seekp(ioData.tellg());
			// Output a space, then the new number
			ioData << " " << inNewNumber;
			break;
		}
		// Read the current number to advance the stream
		ioData >> number;
	}
	return true;
}


int main() {
	char c;

	cout << "---------------------------" << endl;
	//file_stream();

	changeNumberForId("NumberDb.txt", 123, "123-666-5678");
	cin >> c;
	return 0;
}
