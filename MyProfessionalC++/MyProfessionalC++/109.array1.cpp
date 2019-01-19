#include <iostream>
#include <array>


using namespace std;



void array_test() {
	array<int, 3> arr = { 9, 8, 7 };

	cout << "Array size = " << arr.size() << endl;

	for (const auto& i : arr) {
		cout << i << endl;
	}

	cout << "performing arr.fill(3)..." << endl;
	arr.fill(3);

	for (auto iter = cbegin(arr); iter != cend(arr); ++iter) {
		cout << *iter << endl;
	}
}


int main() {
	char c;

	array_test();

	cin >> c;
}