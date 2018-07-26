#include <iostream>
#include <vector>
using namespace std;


void vector_test1() {
	vector<int> vt;

	cout << "size" << vt.size() << endl;
	vt.resize(10);
	vt[0] = 1;
	cout << "size" << vt.size() << endl;
	vt[10] = 2;
}



int main() {
	char c;

	vector_test1();

	cin >> c;
}
