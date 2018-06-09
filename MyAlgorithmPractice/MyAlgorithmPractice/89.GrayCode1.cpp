#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> r;

		if (n <= 0) {
			r.push_back(0);
			return r;
		}

		r.push_back(0);
		r.push_back(1);


		for (int i = 1; i < n; i++) {
			for (int j = r.size() -1; j >= 0; j--) {
				r.push_back(r[j] | (0x1 << i));
			}
		}
		return r;
	}
};



int main() {
	int i;
	Solution s;
	s.grayCode(4);

	cin >> i;
}