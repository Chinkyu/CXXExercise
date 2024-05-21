// easy
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
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
	int addRungs(vector<int>& rungs, int dist) {
		int ans = 0;

		int pre = 0;
		for (int i = 0; i < rungs.size(); ++i) {
			int gap = rungs[i] - pre;

			if (gap > dist) {
				ans += ceil((double)gap / dist) - 1;
			}

			pre = rungs[i];
		}

		return ans;
	}
};


int main() {
	char c;
	Solution sol;

	vector<int> rungs = { 3 }; // { 3, 4, 6, 7 };

	cout << sol.addRungs(rungs, 2);

	cin >> c;
}