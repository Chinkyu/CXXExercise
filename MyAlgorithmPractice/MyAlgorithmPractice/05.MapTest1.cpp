#include <iostream>
#include <map>

using namespace std;

void map_test1() {
	map<string, int> m1;

	m1.insert(make_pair("a", 1));
	m1["b"] = 2;
	m1["c"] = 3;
	m1.insert(make_pair("c", 4));

	for (auto i : m1) {
		cout << i.first.c_str() << " " << i.second << endl;
	}

}


void string_test() {
	string st = "string test";

	cout << st.c_str();

}

int main() {
	char c;
	map_test1();

	cin >> c;
}
