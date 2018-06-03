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
			for (int i = 0 ; i < max; i++) {
				cout << v[i] << " ";
			 
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
				for (int i = 0; i < max; i++) {
					visited[i] = false;
				}
			}

			if (visited[i] == true) continue;
			v[idx] = i;
			visited[i] = true;
			exhaustive_iteration2(idx + 1, max);
			visited[i] = false;
		}
	}
};


int main() {
	int i; 

	Solution s(20);

//	s.exhaustive_iteration1(0, 3);
	s.exhaustive_iteration2(0, 4);

	cin >> i;

}