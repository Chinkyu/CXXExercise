// 타임아웃나서 답봤음 :  바이너리 써치??? 
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
	vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
		vector<int> candels;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '|') {
				candels.push_back(i);
			}
		}
		candels.push_back(1e7);
		vector<int> ans;
		for (int i = 0; i < queries.size(); i++) {
			int lower = lower_bound(candels.begin(), candels.end(), queries[i][0]) - candels.begin();
			int upper = upper_bound(candels.begin(), candels.end(), queries[i][1]) - candels.begin();
			if (candels[lower] == 1e7 || upper <= lower) {
				ans.push_back(0); continue;
			}
			int cnt = upper - lower;
			if (cnt <= 1) {
				ans.push_back(0); continue;
			}
			int totalCnt = candels[upper - 1] - candels[lower] + 1 - cnt;
			ans.push_back(totalCnt);
		}
		return ans;
	}
};

class _Solution {
public:
	vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
		int len = s.size();
		vector<int> v(len, 0);
		vector<int> ans(queries.size(), 0);

		int cnt = 1;
		for (int i = 0; i < len; ++i) {
			if (s[i] == '*') v[i] = cnt++;
		}

		int idx = 0;
		for (auto &it : queries) {
			int l = it[0], r = it[1];

			// left process
			while (v[l] != 0 && l < len) l++;
			while (v[l] == 0 && l < len) l++;

			// right process
			while (v[r] != 0 && 0 < r) r--;
			while (v[r] == 0 && 0 < r) r--;

			if (l > r) {
				ans[idx++] = 0;
			}
			else if(l == r) {
				ans[idx++] = 1;
			}
			else {
				ans[idx++] = (v[r] - v[l] + 1);
			}

			if (idx == 7730) {
				cout << idx;
			}

		}

		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	//string s = "**|**|***|";
	//vector<vector<int>> queries = { {2, 5}, {5, 9} };

	string s = "***|**|*****|**||**|*";
	vector<vector<int>> queries = { {1, 17}, {5, 11} };

	vector<int> ans = sol.platesBetweenCandles(s, queries);

	for (auto &it : ans) {
		cout << it << " " ;
	}

	cin >> c;
}