//	int index 로 변환 해 가면서 풀어서 쉽게 풀림
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

	vector<int> getPattern(string &w) {
		int n = w.size();
		unordered_map<int, int> m;
		vector<int> p;

		int idx = 1;
		for (int i = 0; i < n; ++i) {
			if (m.find(w[i]) != m.end()) {
				p.push_back(m[w[i]]);
				continue;
			}

			// not found
			m[w[i]] = idx;
			p.push_back(idx);
			idx++;
		}
		return p;
	}

	vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
		vector<string> ans;
		vector<int> pV = getPattern(pattern);

		for (auto it : words) {
			vector<int> v = getPattern(it);
			if (pV == v) {
				ans.push_back(it);
			}
		}
		return ans;
	}
};

int main() {
	char c;

	Solution sol;
	vector<string> nums = { "abc","deq","mee","aqq","dkd","ccc" };
	vector<string> ans = sol.findAndReplacePattern(nums, "abb");

	for (auto it : ans) {
		cout << it << " ";
	}

	cin >> c;
}