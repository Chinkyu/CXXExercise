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

using namespace std;

class Solution {
public:
	int minimumRounds(vector<int>& tasks) {
		unordered_map<int, int> m;

		int ans = 0;
		for (auto &it : tasks) {
			m[it]++;
		}

		for (auto &it : m) {
			int div = it.second / 3;
			int rem = it.second % 3;

			if (div == 0 && rem == 1) return -1;
			ans += div;
			if (rem >= 1) ans++;
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<vector<int>> circles = { {2, 2, 2}, {3, 4, 1} };

	cout << sol.countLatticePoints(circles);

	cin >> c;

}