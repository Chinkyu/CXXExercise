#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



void removeEmptyStrings(vector<string>& strings) {
	auto it = remove_if(strings.begin(), strings.end(),
		[](const string& str) { return str.empty(); });
	// erase the removed elements
	strings.erase(it, end(strings));
}

void testRemoveReaseScheme() {
	vector<string> myVector = { "", "one", "", "two", "three", "four" };
	for (auto& itr : myVector) {
		cout << "\"" << itr << "\" ";
	}

	removeEmptyStrings(myVector);

	for (auto& itr : myVector) {
		cout << "\"" << itr << "\" ";
	}
	cout << endl;
}

int main() {
	char c;

	testRemoveReaseScheme();

	cin >> c;
}