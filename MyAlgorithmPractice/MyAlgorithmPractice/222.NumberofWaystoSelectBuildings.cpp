// 010, 010  패턴으로 경우수 따짐  쉽게 해결 됨... 
// count array  사용
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
	long long numberOfWays(string s) {
		vector<int> v(s.size(), 0), ac(s.size(), 0);
		long long ans = 0;

		for (int i = 0; i < s.size(); ++i) v[i] = s[i] - '0';

		ac[0] = v[0];
		for (int i = 1; i < s.size(); ++i) ac[i] = v[i] + ac[i - 1];

		int one_num = ac[s.size() - 1];
		for (int i = 1; i < s.size() - 1; ++i) {
			if (v[i] == 1) {	// 010
				int lnum = i + 1 - ac[i];   // left zero num
				int rnum = s.size() - 1 + 1 - one_num  - lnum; // right zero num

				if (lnum > 0 && rnum > 0) ans += lnum * rnum;

			}
			else {				// 101
				int lnum = ac[i];  // left one num
				int rnum = one_num - lnum; // right one num

				if (lnum > 0 && rnum > 0) ans += lnum * rnum;
			}
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;
	
	string s = "001101";
	cout << sol.numberOfWays(s);

	cin >> c;
}