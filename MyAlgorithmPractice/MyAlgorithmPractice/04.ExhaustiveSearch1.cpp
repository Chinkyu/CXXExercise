#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> v; //  = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	Solution(int num): v( num, 0) {
//		v = { 1, 2, 3 };
	}

	void exhaustive_iteration1(int idx, int max) {

		if (idx == max) {
			// print 
			for (int i = 0 ; i < max; i++) {
				cout << v[i] << " ";
			}
			cout << endl;
			return;
		}

		for (int i = 0; i < max; i++) {
			v[idx] = i;
			exhaustive_iteration1(idx + 1, max);
		}
	}
};


int main() {
	Solution s(20);

	s.exhaustive_iteration1(0, 4);
	getchar();

}