//	가지가 많은 시에 가산점을 많이 주면 됨....... 
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
	long long maximumImportance(int n, vector<vector<int>>& roads) {
		vector<pair<int,int>> num(n, make_pair(0,0));
		vector<int> importance(n, 0);

		for (int i = 0; i < n; ++i) {
			num[i].first = i;
		}

		for (auto it : roads) {
			num[it[0]].second++;
			num[it[1]].second++;
		}

		sort(num.begin(), num.end(), 
			[](pair<int, int> l, pair<int, int> r) {
				return l.second > r.second; 
			}
		);

		for (int i = 0, j = n; i < n; ++i,--j) {
			importance[num[i].first] = j;
		}

		long long ans = 0;
		for (auto it : roads) {
			ans += importance[it[0]] + importance[it[1]];
		}
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<vector<int>> roads = { {0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4} };
	cout << sol.maximumImportance(5, roads);

	cin >> c;
}
