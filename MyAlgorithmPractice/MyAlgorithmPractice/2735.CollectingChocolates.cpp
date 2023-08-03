// dijkstra 비슷하게 품..  디버깅 오래걸림. 
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
#include <cmath>

using namespace std;

class Solution {
public:
	long long minCost(vector<int>& nums, int x) {
		long long tmin = INT_MAX, tsum;

		for (auto it : nums) {
			tmin = min(tmin, (long long)it);
			tsum += it;
		}

		long long ca = tmin * nums.size() + (x * nums.size() - 1);
		return min(ca, tsum);
	}
};

int main() {
	char c;

	Solution sol;

	//vector<vector<int>> edges = { {0, 1, 2}, {1, 2,3}, {2, 3, 2},{0, 3,4 } };
	vector<vector<int>> edges = { {0, 1, 2},{0, 2, 4},{1, 3, 1},{2, 3, 3},{3, 4, 2} };
	vector<int> marked = { 0, 4 };
	cout << sol.minimumDistance(5, edges, 1, marked);
	//cout << sol.longestString(3, 25, 48);

	cin >> c;
}
