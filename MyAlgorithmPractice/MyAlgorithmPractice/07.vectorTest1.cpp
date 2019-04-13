#include <iostream>
#include <vector>
using namespace std;


//void vector_test1() {
//	vector<int> vt;
//
//	cout << "size" << vt.size() << endl;
//	vt.resize(10);
//	vt[0] = 1;
//	cout << "size" << vt.size() << endl;
//	vt[10] = 2;
//}
//
//void vector_test2() {
//
//	// initialize 10x10 vector with all are 0
//	vector<int, vector<int>> vt(10, vector<int>(10, 0));
//
//}

void vector_test3(vector<string> &sv) {
	string s1 = "1234567890";

	for (int i = 0; i < 100; i++) {
		sv.push_back(s1);
	}
}


int main() {
	char c;

	//vector_test1();

	vector<string> sv;

	vector_test3(sv);

	for (auto it : sv) {
		cout << it.c_str() << " ";
	}
	cout << endl;

	cin >> c;
}
