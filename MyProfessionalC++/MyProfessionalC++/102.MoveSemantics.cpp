#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Move Semantics

class SpreadsheetCell {
	int mValue;

};


class Spreadsheet {

public:
	int mWidth;
	int mHeight;
	SpreadsheetCell *mCells;

	Spreadsheet(int width, int height) { mWidth = width; mHeight = height; }
	Spreadsheet(Spreadsheet&& src) noexcept;   // Move constructor
	Spreadsheet& operator=(Spreadsheet&& rhs) noexcept;  // Move assignment

	// If you want to define your own move constructor and use the default copy constructor, you need to declare it as default
	Spreadsheet& operator=(Spreadsheet& rhs) = default;
};

// Move Constructor
Spreadsheet::Spreadsheet(Spreadsheet&& src) noexcept {

	// Shallow copy of data
	mWidth = src.mWidth;
	mHeight = src.mHeight;
	mCells = src.mCells;

	cout << "Spreadshtte move constructor called" << endl;

	// Reset the src object, because ownership has been moved!
	src.mWidth = 0; 
	src.mHeight = 0;
	src.mCells = nullptr;
}

// Move assignment operator
Spreadsheet& Spreadsheet::operator=(Spreadsheet&& rhs) noexcept {

	if (this == &rhs) {
		return *this;
	}

	cout << "Spreadshtte move assignment called" << endl;
	// free the old memory
//	if (mCells != nullptr) free(mCells);   //:: ckkang : XXXX 

	// Shallow copy of data
	mWidth = rhs.mWidth;
	mHeight = rhs.mHeight;
	mCells = rhs.mCells;

	// Reset the rhs object, because ownership has been moved!
	rhs.mWidth = 0;
	rhs.mHeight = 0;
	rhs.mCells = nullptr;


}


Spreadsheet CreateObject() {
	return Spreadsheet(3, 2);
}


int main() {
	char c;
	vector<Spreadsheet> vec;

	for (int i = 0; i < 2; ++i) {
		cout << "Iteration " << i << endl;
		vec.push_back(Spreadsheet(100, 100));
		cout << endl;
	}
	Spreadsheet s(2, 3);
	s = CreateObject();
	Spreadsheet s2(5, 6);
	s2 = s;    /// <- call copy constructor, becuase s is not temporary objects

	cin >> c;
	return 0;
}
