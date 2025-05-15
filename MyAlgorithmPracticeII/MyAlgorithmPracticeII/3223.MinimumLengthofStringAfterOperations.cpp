// easy
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>
#include <set>
#include <list>
#include <regex>
#include <memory>

using namespace std;

// even numbe -> 2, odd number -> 1

class Solution {
public:
	int minimumLength(string s) {
		unordered_map<char, int> um;

		for (auto& it : s) {
			um[it]++;
		}

		int ans = 0;
		for (auto& it : um) {
			if (it.second % 2 == 1) {
				ans++;
			}
			else {
				ans += 2;
			}
		}

		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	string s = "abaacbcbb";


	cout << sol.minimumLength(s);

	cin >> c;
}