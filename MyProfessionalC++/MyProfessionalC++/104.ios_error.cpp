#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void ios_check() {
	cout << cout.exceptions() << endl;
	cout.exceptions(ios::eofbit);
	cout << cout.exceptions() << endl;
}

void ios_exception() {

	cout.exceptions(ios::failbit | ios::badbit || ios::eofbit);
	try {
		cout << "Hello World." << endl;
	}
	catch (const ios_base::failure& ex) {
		cerr << "Caught exception: " << ex.what()
			<< ", error code = " << ex.code() << endl;
	}

}

void cin_test1() {
	string in;


	cin >> in;
	cout << "in : " << in << endl;

}

void cin_test2() {
	int i = 3;

	cin >> i;
	cout << "i : " << i << endl;
	   
}

// ----------------------------------------------------
string readName1(istream& inStream) {
	string name;
	while (!inStream.fail()) {
		int next = inStream.get();
		if (next == std::char_traits<char>::eof())
			break;
		name += static_cast<char>(next);  // Append char
	}
	return name;
}

string readName2(istream& inStream) {
	string name;
	char next;

	while (inStream.get(next)) {
		name += next;  // Append char
	}
	return name;
}

//----------------------------------------
void getReservationData1() {
	string guestName;
	int partySize;
	cout << "Name and number of guests: ";
	cin >> guestName >> partySize;
	cout << "Thank you, " << guestName << "." << endl;
	if (partySize > 10) {
		cout << "An extra gratuity will apply." << endl;
	}
}

void getReservationData2() {
	string guestName;
	int partySize = 0;
	
	// Read characters until we find a digit
	char ch;
	cin >> noskipws;
	while (cin >> ch) {
		if (isdigit(ch)) {
			cin.unget();
			if (cin.fail())
				cout << "unget() failed" << endl;
			break;
		}
		guestName += ch;
	}
	
	// Read partysize
	cin >> partySize;
	cout << "Thank you '" << guestName
		<< "', party of " << partySize << endl;
	if (partySize > 10) {
		cout << "An extra gratuity will apply." << endl;
	}
}

//---------------------------------------
int Calcurator1() {
	cout << "Enter numbers on seperate lines to add. "
		<< "Use Control+D to finish (Control+Z in Windows)." << endl;

	int sum = 0;
	if (!cin.good()) {
		cerr << "Standard input is in a bad state!" << endl;
		return 1;
	}
	int number;
	while (!cin.bad()) {
		cin >> number;
		if (cin.good()) {
			sum += number;
		}
		else if (cin.eof()) {
			break; // Reached end of file
		}
		else if (cin.fail()) {
			// Failure!
			cin.clear(); // Clear the failure state.
			string badToken;
			cin >> badToken;
			cerr << "WARNING: Bad input encountered: " << badToken << endl;
		}
	}

	cout << "The sum is " << sum << endl;
}

// -------------------------------------
void tokenizer() {
	cout << "Enter tokens. Control+D(Unix) or Control+Z(Windows) to end" << endl;
	ostringstream outStream;
	while (cin) {
		string nextToken;
		cout << "Next token: ";
		cin >> nextToken;
		if (nextToken == "done")
			break;
		outStream << nextToken << "\t";
	}
	cout << "The end reault is: " << outStream.str();
}


int main() {
	char c;

//	ios_check();
//	ios_exception();
	cout << "---------------------------" << endl;
//	cin_test1();
//	cin_test2();

//	readName1(cin);
//	readName2(cin);

//	getReservationData1();
//	getReservationData2();

//	Calcurator1();
	tokenizer();

	cin >> c;
	return 0;
}
