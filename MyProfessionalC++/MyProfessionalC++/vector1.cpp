#include <string>
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;
int main() {

	vector<string> myVector = { "A first string", "A second string" };
	myVector.push_back("A third string");
	myVector.push_back("A last string int the vector");

	for (const auto& str : myVector) {
		cout << str << endl;
	}

	for (auto iterator = cbegin(myVector); iterator != cend(myVector); ++iterator) {
		cout << *iterator << endl;
	}

	auto itr = begin(myVector);
	cout << *itr;

	getchar();

	return 0;
}