// 쉽게 풀림... 

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
	vector<string> findRepeatedDnaSequences(string s) {
		map<string, int> m;
		int l = s.size();
		vector<string> ans;

		for (int i = 0; i <= l - 10; ++i) {
			m[s.substr(i, 10)]++;
		}

		for (auto it : m) {
			if (it.second > 1) ans.push_back(it.first);
		}
		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	string s = "AAAAAAAAAAA"; //  "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"; //  "011010";
	vector<string> v = sol.findRepeatedDnaSequences(s);

	for (auto it : v) {
		cout << it << endl;
	}

	cin >> c;
}