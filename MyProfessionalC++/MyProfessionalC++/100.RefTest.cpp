#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Once reference create and initialized, it can't be changed(address)
void ref_test() {
	int x = 3, y = 4;

	int& ref = x;
	cout << "ref = " << &ref << " " << ref << endl;

	ref = y;
	cout << "ref = " << &ref << " " << ref << endl;

	// error 
//	&ref = &y;
}

// reference to pointer 
void ref_test2() {
	int* intP;
	int*& ptrRef = intP;

	ptrRef = new int;
	*ptrRef = 5;

	cout << *ptrRef << " " << *intP << " : " << ptrRef << " " << intP << endl;
}

// reference to const 

void refcall(int& t) { ++t; }


void ref_test3() {

	int* ptr = (int *)8;
	refcall(*ptr);
}

//---------- reference to pointer ----------------
void seperateOddsAndEvens(const int arr[], int size, int *& odds, int &numOdds, int *&evens, int& numEvens) {
	numOdds = numEvens = 0;
	
	for (int i = 0; i < size; ++i) {
		if (arr[i] % 2 == 1) {
			++numOdds;
		}
		else {
			++numEvens;
		}
	}

	odds = new int[numOdds];
	evens = new int[numEvens];
	int oddsPos = 0, evenPos = 0;
	for (int i = 0; i < size; ++i) {
		if (arr[i] % 2 == 1) {
			odds[oddsPos++] = arr[i];
		}
		else {
			evens[evenPos++] = arr[i];
		}
	}
}


void ref_test4() {
	int unSplit[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int *oddNums, *evenNums;
	int numOdds, numEvens;
	seperateOddsAndEvens(unSplit, 10, oddNums, numOdds, evenNums, numEvens);
}

//---------- reference to pointer[vector version] ----------------
void seperateOddsAndEvens5(const vector<int>& arr, int size, vector<int> &odds, int &numOdds, vector<int> &evens, int& numEvens) {
	numOdds = numEvens = 0;

	for (int i = 0; i < size; ++i) {
		if (arr[i] % 2 == 1) {
			++numOdds;
		}
		else {
			++numEvens;
		}
	}

	odds.reserve(numOdds);   // reserve memory, not actually occupy...
	evens.reserve(numEvens);

	int oddsPos = 0, evenPos = 0;
	for (int i = 0; i < size; ++i) {
		if (arr[i] % 2 == 1) {
			odds.push_back(arr[i]);
		}
		else {
			evens.push_back(arr[i]);
		}
	}
}


void ref_test5() {
	vector<int> unSplit = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> oddNums, evenNums;
	int numOdds, numEvens;
	seperateOddsAndEvens5(unSplit, 10, oddNums, numOdds, evenNums, numEvens);
}



void main() {
	char c;

	cout << "reference testing" << endl;

	ref_test();
	ref_test2();

	// This will crash... or some problem because it reference const and try to change
	//ref_test3();

	// reference to pointer
	ref_test4();
	ref_test5();

	cin >> c;
}
