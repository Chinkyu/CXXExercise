//  easy
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <iomanip>
#include <cmath>

using namespace std;

class Solution {
public:
	int minSteps(string s, string t) {
		unordered_map<char, int> m;

		for (auto &it : s) m[it]++;
		for (auto &it : t) m[it]--;

		int ans = 0;
		for (auto &it : m) {
			if (it.second != 0) ans += abs(it.second);
		}
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> time = { 5, 10, 10 };

	cout << sol.minSteps("leetcode", "coats");

	cin >> c;

}