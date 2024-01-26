// easy
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	int numberOfBeams(vector<string>& bank) {
		vector<int> v;

		for (auto &it : bank) {
			int cnt = 0;
			for (auto &jt : it) {
				if (jt == '1') cnt++;
			}
			if (cnt != 0) v.push_back(cnt);
		}

		int ans = 0;
		for (int i = 1; i < v.size(); ++i) {
			ans += v[i - 1] * v[i];
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;
	vector<string> bank = { "000","111","000" };
	//vector<string> bank = {"011001", "000000", "010100", "001000" };

	cout << sol.numberOfBeams(bank);

	cin >> c;
}