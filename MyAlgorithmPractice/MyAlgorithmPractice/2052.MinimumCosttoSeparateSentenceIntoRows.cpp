//  ¥‰∫√¿Ω : 
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
	int minimumCost(string sentence, int k) {
		if (sentence.size() <= k) return 0;
		string buff;
		vector<string> words;
		istringstream iss(sentence);
		while (iss >> buff) words.push_back(buff);
		int n = words.size();
		vector<int> dp(n, INT_MAX);
		dp.back() = 0;
		for (int i = n - 2; i >= 0; --i) {
			int prefix = -1;
			for (int j = i; j < n; ++j) {
				prefix += 1 + words[j].size();
				if (prefix <= k) dp[i] = j == n - 1 ? 0 : min(dp[i], (k - prefix)*(k - prefix) + dp[j + 1]);
				else break;
			}
		}
		return dp[0];
	}
};

class _Solution {
public:
	int minimumCost(string sentence, int k) {
		int l = sentence.size();
		vector<int> v;

		int cnt = 0;
		for (int i = 0; i < l; ++i) {
			if (sentence[i] == ' ') {
				v.push_back(cnt);
				cnt = 0;
			}
			else {
				cnt++;
			}

			if (i == l - 1) {
				v.push_back(cnt);
			}
		}
		
		int vl = v.size();

		int ans = 0;

		int ccount = v[0];
		for (int i = 1; i < vl; ++i) {
			if (k < ccount + v[i] + 1) {
				ans += (k - ccount) * (k - ccount);
			}
			else {
				ccount = ccount + v[i] + 1;
			}
		}

		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	string sentence = "i love leetcode";

	cout << sol.minimumCost(sentence, 12);

	cin >> c;
}