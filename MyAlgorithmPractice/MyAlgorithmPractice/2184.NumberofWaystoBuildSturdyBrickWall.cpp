//  답봤음 
//  모든 컨비네이션 찾은후에.. 중복되지 않는  그래프를 만든뒤에  트레버스 하면서 개수를 찾아 낸다 
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
	int dp[101][1024] = {};
	int dfs_h(int h, int prev, const vector<int>& masks) {
		if (h == 0)
			return 1;
		if (dp[h][prev] == 0)
			for (int mask : masks)
				if ((mask & prev) == 0)
					dp[h][prev] = (dp[h][prev] + dfs_h(h - 1, mask, masks)) % 1000000007;
		return dp[h][prev];
	}
	vector<int> dfs_w(int w, int width, vector<int>& bricks, int mask, vector<int> &masks) {
		if (w == width)
			masks.push_back(mask);
		else {
			if (w)
				mask += (1 << (w - 1));
			for (int b : bricks)
				if (w + b <= width)
					dfs_w(w + b, width, bricks, mask, masks);
		}
		return masks;
	}
	int buildWall(int height, int width, vector<int>& bricks) {
		return dfs_h(height, 0, dfs_w(0, width, bricks, 0, vector<int>() = {}));
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> bricks = { 1, 2 };

	cout << sol.buildWall( 2, 3, bricks);

	cin >> c;

}