// sliding window
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
	int maximumWhiteTiles(vector<vector<int>>& tiles, int x) {
		sort(tiles.begin(), tiles.end());
		int cnt = 0, ans = 0, n = tiles.size();
		for (int i = 0, j = 0; i < n; i++) {
			if (i > 0) cnt -= tiles[i - 1][1] - tiles[i - 1][0] + 1;

			while (j < n && tiles[j][1] - tiles[i][0] + 1 <= x) {
				cnt += tiles[j][1] - tiles[j][0] + 1;
				j++;
			}
			int addi = 0;
			if (j < n) addi = max(0, tiles[i][0] + x - tiles[j][0]);
			ans = max(ans, cnt + addi);
		}
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> special = { 7, 6, 8 };
	cout << sol.maxConsecutive(6, 8, special);

	cin >> c;

}