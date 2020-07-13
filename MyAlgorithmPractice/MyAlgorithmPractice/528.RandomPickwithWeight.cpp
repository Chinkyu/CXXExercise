#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Solution {
public:
	vector<int> acu;
	int sz= 0, scope = 0;
	Solution(vector<int>& w) {
		sz = w.size();
		srand(time(NULL));

		acu.resize(sz);

		acu[0] = w[0];
		for (int i = 1; i < sz; ++i) {
			acu[i] = acu[i - 1] + w[i];
		}
		scope = acu[sz - 1];
	}

	int pickIndex() {

		int r = rand() % scope;

		// binary search r
		int s = 0, e = sz;
		int m = 0;
		do {
			m = (s + e) / 2;
			if (m == 0) {
				return m;
			}
			else if (acu[m - 1] < r && r <= acu[m]) {
				return m;
			}
			else if (r <= acu[m - 1]) {
				e = m;
			}
			else if (acu[m] < r) {
				s = m;
			}
		} while (s != e);

		m = s;
		return m;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

int main() {
	char c;
	vector<int> w = { 1, 1, 1, 1 };
	Solution *obj = new Solution(w);

	cout << obj->pickIndex() << endl;
	cout << obj->pickIndex() << endl;
	cout << obj->pickIndex() << endl;

	cin >> c;
}