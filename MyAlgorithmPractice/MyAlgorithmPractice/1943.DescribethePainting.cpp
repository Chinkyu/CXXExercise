// easy : sliding window
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
	vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
		vector<vector<int>> s;

		for (auto &it : segments) {
			s.push_back({ it[0], it[2] });
			s.push_back({ it[1], -it[2] });
		}

		sort(s.begin(), s.end(),
			[](vector<int> &l, vector<int> &r) {
			return l[0] < r[0];
		}
		);

		long long pre_level = 0, level = 0;
		int pre_idx = -1, idx = -1;
		vector<vector<long long>> ans;
		for (int i = 0; i < s.size(); ++i) {
			if (idx != s[i][0]) {  // different - check previous.
				//if (pre_level != level) 
				{
					pre_level = level;
					if(pre_level != 0) ans.push_back({ pre_idx, s[i][0], pre_level });
					pre_idx = s[i][0];		
				}

				pre_idx = s[i][0];
				level += s[i][1];
			}
			else {
				level += s[i][1];
			}
			idx = s[i][0];
		}

		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	vector<vector<int>> segments = {{1, 4, 5}, {1, 4, 7}, {4, 7, 1}, {4, 7, 11}};

	vector<vector<long long>> ans =  sol.splitPainting(segments);

	for (auto &it : ans) {
		for (auto &jt : it) {
			cout << jt << " ";
		}
		cout << endl;
	}

	cin >> c;
}