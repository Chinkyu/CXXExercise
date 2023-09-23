//  ½±°Ô ÇØ°áµÊ... 

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
	string removeStars(string s) {
		int l = s.size();
		string ans;

		for (int i = 0; i < l; ++i) {
			if (s[i] == '*') {
				ans.pop_back();
			}
			else {
				ans.push_back(s[i]);
			}
		}
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<string> garbage = { "G", "P", "GP", "GG" };
	vector<int> travel = { 2, 4, 3 };

	cout << sol.garbageCollection(garbage, travel);

	cin >> c;
}