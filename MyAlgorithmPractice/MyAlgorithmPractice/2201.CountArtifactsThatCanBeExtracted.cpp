//  Normal : accumulation array  »ç¿ë
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
	int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
		vector<vector<int>> digMap(n+1, vector<int>(n+1, 0));
		vector<vector<int>> acc(n+1, vector<int>(n+1, 0));

		for (auto &it : dig) {
			digMap[it[0]+1][it[1]+1] = 1;
		}

		for (int i = 1; i < n+1; ++i) {
			for (int j = 1; j < n+1; ++j) {
				acc[i][j] = digMap[i][j] + acc[i - 1][j] + acc[i][j - 1] - acc[i - 1][j - 1];
			}
		}

		int ans = 0;
		for (auto &it : artifacts) {
			for (int j = 0; j < 4; ++j) it[j]++;
			int num = (it[2] - it[0] + 1) * (it[3] - it[1] + 1);

			int cnum = acc[it[2]][it[3]] - acc[it[2]][it[1]-1] - acc[it[0] - 1][it[3]] 
						+ acc[it[0] - 1][it[1] - 1];

			if (num == cnum) ans++;
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;


	vector<vector<int>> artifacts = {{0, 0, 0, 0}, {0, 1, 1, 1}};
	vector <vector<int>> dig = { {0, 0}, {0, 1}, {1, 1} };
	cout << sol.digArtifacts(2, artifacts, dig);

	cin >> c;

}