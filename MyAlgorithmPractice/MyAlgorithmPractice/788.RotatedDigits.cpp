//	1,3,7 등이 있을때 선택 안하는 부분 넣어서 해결
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;


class Solution {
public:
	int rotatedDigits(int n) {
		unordered_map<int, int> m;
		int ans = 0;

		for (int i = 1; i <= n; ++i) {
			m.clear();
			int d = i;

			while (d > 0) {
				int r = d % 10;
				if (r == 0 || r == 1 || r == 8 || r == 2 || r == 5
					|| r == 6 || r == 9) {
					m[r]++;
				}
				else {
					goto endloop;
				}
				d = d / 10;
			}

			if (m[2] > 0 || m[5] > 0 || m[6] > 0 || m[9] > 0) {
				//cout << i << endl;
				ans++;
			}
		endloop:
			cout << ".";
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	cout << sol.rotatedDigits(857);

	cin >> c;
}