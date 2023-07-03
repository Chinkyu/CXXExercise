//	accumulated array   가   prefix aligne의 accumulated array와 같으면  bingo...
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
	int numTimesAllBlue(vector<int>& flips) {
		vector<int> sf = flips;
		int n = flips.size();

		vector<int> asf(n, 0), af(n, 0);  // accumulated sorted flips, accumulated flips
		int ans = 0;

		sort(sf.begin(), sf.end());

		asf[0] = sf[0];
		af[0] = flips[0];
		for (int i = 1; i < n; ++i) {
			asf[i] = asf[i - 1] + sf[i];
			af[i] = af[i - 1] + flips[i];
		}


		// if both accumulated number same.. it mean match 
		for (int i = 0; i < n; ++i) {
			if (asf[i] == af[i] )  ans++;
		}
		return ans;
	}
};

int main() {
	char c;

	Solution sol;
	vector<string> nums = { "abc","deq","mee","aqq","dkd","ccc" };
	vector<string> ans = sol.findAndReplacePattern(nums, "abb");

	for (auto it : ans) {
		cout << it << " ";
	}

	cin >> c;
}