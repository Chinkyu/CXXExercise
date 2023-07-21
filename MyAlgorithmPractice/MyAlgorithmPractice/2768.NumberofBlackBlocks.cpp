// 그냥 풀면 타임아웃. 맵으로 필요한곳만 처리해야 됨. 
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
	vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
		vector<long long> ans(5, 0);
		map<pair<int, int>, int>  mat;

		for (auto it : coordinates) {
			int l = it[0], c = it[1];

			if (0 <= l - 1 && l - 1 < m - 1 && 0 <= c - 1 && c - 1 < n - 1) {
				mat[make_pair(l - 1, c - 1)]++;
			}
			if (0 <= l && l < m - 1 && 0 <= c - 1 && c - 1 < n - 1) {
				mat[make_pair(l, c - 1)]++;
			}
			if (0 <= l - 1 && l - 1 < m - 1 && 0 <= c && c < n - 1) {
				mat[make_pair(l - 1, c)]++;
			}
			if (0 <= l && l < m - 1 && 0 <= c && c < n - 1) {
				mat[make_pair(l, c)]++;
			}
		}

		for (auto it : mat) {
			ans[it.second]++;
		}
		ans[0] = ((long long)(m-1)*(long long)(n-1)) - mat.size();

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<vector<int>> coordinates = { {0, 0},{1, 1},{0, 2} };
	vector<long long> ans = sol.countBlackBlocks(3, 3, coordinates);
	
	for (auto it : ans) cout << it << " ";

	cin >> c;
}
