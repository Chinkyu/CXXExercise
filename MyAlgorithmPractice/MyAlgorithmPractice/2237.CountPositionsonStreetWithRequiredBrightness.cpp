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

// timeout 
class _Solution {
public:
	int meetRequirement(int n, vector<vector<int>>& lights, vector<int>& requirement) {
		vector<int> b(n, 0);

		for (auto &it : lights) {
			int lb = max(0, it[0] - it[1]);
			int hb = min(n - 1, it[0] + it[1]);

			for (int j = lb; j <= hb; ++j) {
				b[j]++;
			}
		}

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (requirement[i] <= b[i]) ans++;
		}

		return ans;
	}
};

// sliding window
class Solution {
public:
	int meetRequirement(int n, vector<vector<int>>& lights, vector<int>& requirement) {
		vector<int> b(n, 0);
		unordered_map<int, int> bm;

		int min_lb = 0;
		for (auto &it : lights) {
			int lb = max(0, it[0] - it[1]);
			int hb = min(n - 1, it[0] + it[1]);

			min_lb = min(min_lb, lb);
			bm[lb]++;
			bm[hb+1]--;
		}

		int level = 0;
		for (int i = min_lb; i < n; ++i) {
			if (bm.find(i) != bm.end()) {
				level += bm[i];
			}
			if(i >= 0) b[i] = level;
		}

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (requirement[i] <= b[i]) ans++;
		}

		return ans;
	}
};


int main() {
	char c;

	Solution sol;

	//vector<vector<int>> lights = { {0, 1}, {2, 1}, {3, 2} };
	//vector<int> requirement = { 0, 2,1, 4, 1 };
	//cout << sol.meetRequirement(5, lights, requirement);

	vector<vector<int>> lights = { {0, 1}};
	vector<int> requirement = { 2 };
	cout << sol.meetRequirement(1, lights, requirement);


	cin >> c;

}