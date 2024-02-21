// easy
#include <iostream>
#include <vector>
#include <unordered_map>
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
	string addSpaces(string s, vector<int>& spaces) {
		string ans;

		int space_idx = 0;
		int next_space = (space_idx < spaces.size()) ? spaces[space_idx] : -1;
		for (int i = 0; i < s.size(); ++i) {
			if (i == next_space) {
				ans.push_back(' ');
				space_idx++;
				next_space = (space_idx < spaces.size()) ? spaces[space_idx] : -1;
			}
			ans.push_back(s[i]);
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	string s = "LeetcodeHelpsMeLearn";
	vector<int> spaces = { 8, 13, 15 };

	cout << sol.addSpaces(s, spaces);

	cin >> c;
}