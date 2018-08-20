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

void vector_test2() {

	// initialize 10x10 vector with all are 0
	vector<int, vector<int>> vt(10, vector<int>(10, 0));

}



int main() {
	char c;

	vector_test1();

	cin >> c;
}
