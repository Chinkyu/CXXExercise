//  easy  , just map... stuff 
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
	int equalPairs(vector<vector<int>>& grid) {
		int l = grid.size();
		map<vector<int>, int> m;

		for (int i = 0; i < l; ++i) {
			m[grid[i]]++;
		}

		int ans = 0;
		for (int i = 0; i < l; ++i) {
			vector<int> tv;
			for (int j = 0; j < l; ++j) {
				tv.push_back(grid[j][i]);
			}

			if (m.find(tv) != m.end()) ans +=m[tv];
		}

		return ans;
	}
};

int main() {
	char c;

	FoodRatings sol;

	vector<int> edges = { 4,4,8,-1,9,8,4,4,1,1 };
	cout << sol.closestMeetingNode(edges, 5, 6);

	cin >> c;

}