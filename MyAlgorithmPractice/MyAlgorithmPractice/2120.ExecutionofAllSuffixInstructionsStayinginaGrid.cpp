//  타임아웃 날쭐 알았는데... 되는군.... 
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
	vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
		int l = s.size();
		vector<int> ans;


		for (int i = 0; i < l; ++i) {
			int li = startPos[0], ci = startPos[1];
			int num = 0;
			for (int j = i; j < l; ++j) {
				switch (s[j]) {
				case 'R':
					ci++;
					break;
				case 'L' :
					ci--;
					break;
				case 'U' :
					li--;
					break;
				case 'D' :
					li++;
					break;
				}

				// check boundary
				if (ci < 0 || n <= ci || li < 0 || n <= li) {
					num = j - i;
					break;
				}
				if (j == l - 1) {
					num = j - i+1;
					break;
				}
			}
			ans.push_back(num);
		}
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> startPos = { 0, 1 };
	vector<int> ans = sol.executeInstructions(3, startPos, "RRDDLU");

	for (auto it : ans) {
		cout << it << " ";
	}

	cin >> c;
}