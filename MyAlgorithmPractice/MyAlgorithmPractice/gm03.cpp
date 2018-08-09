#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
	string line;
	string snum;
	int inum;

	while (getline(cin, line)) {
		istringstream input(line);

		int arr_num;
		getline(input, snum, ';');
		inum = stoi(snum);
		arr_num = inum;

		vector<int> iv(arr_num, 0);

		for (int i = 0; i < arr_num; i++) {
			getline(input, snum, ',');
			inum = stoi(snum);
			iv[inum]++;
		}

		for (int i = 0; i < arr_num; i++) {
			if (iv[i] > 1) cout << i << endl;
		}
	}
}
