#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> v; //  = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	vector<bool> visited;

	Solution(int num): v( num, 0), visited(num, false) {
//		v = { 1, 2, 3 };
	}

	void exhaustive_iteration1(int idx, int max) {

		if (idx == max) {
			// print 
			for (int i = 0; i < max; i++) {
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

	void exhaustive_iteration2(int idx, int max) {

		if (idx == max) {
			for (int i = 0; i < max; i++) {
				cout << v[i] << " ";
			}
			cout << endl;
			return;
		}

		for (int i = 0; i < max; i++) {
			// initialize visited vector
			if (idx == 0) {
				for (int j = 0; j < max; j++) {
					visited[j] = false;
				}
			}

			if (visited[i] == true) continue;
			v[idx] = i;
			visited[i] = true;
			exhaustive_iteration2(idx + 1, max);
			visited[i] = false;
		}
	}

	void exhaustive_iteration3(int idx, int start, int max) {

		if (idx >= 4) {
			for (int i = 0; i < 4; i++) {
				cout << v[i] << " ";
			}
			cout << endl;
			return;
		}

		for (int i = start; i < max; i++) {
			v[idx] = i;
			exhaustive_iteration3(idx + 1, i + 1, max);
		}
	}
};


int main() {
	int i; 

	Solution s(20);

//	s.exhaustive_iteration1(0, 3);
//	s.exhaustive_iteration2(0, 4);
	s.exhaustive_iteration3(0, 0, 10);

	cin >> i;

}