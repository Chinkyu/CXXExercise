//  ¥‰îf¿Ω. 
//Such a deceptive problem.The key is to realize that we need to take all zeros.
//
//Then, we take as many 1 from the right as we can, before exceeding k.It can be shown that greedily using 1 from the right is always better than to skip it.

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
	int longestSubsequence(string s, int k) {
		int val = 0, cnt = 0, pow = 1;
		for (int i = s.size() - 1; i >= 0 && val + pow <= k; --i) {
			if (s[i] == '1') {
				++cnt;
				val += pow;
			}
			pow <<= 1;
		}
		return count(begin(s), end(s), '0') + cnt;
	}

	// stoi  ∞° out of range
	int _longestSubsequence(string s, int k) {
		int l = s.size();
		
		if (s == "0") return 0;


		int kl = 0, tk = k;
		for (int i = 1; i < 10000; ++i) {
			tk = tk / 2;
			if (tk == 0) {
				kl = i;
				break;
			}
		}

		if (stoi(s, 0, 2) < k) return kl;

		int s_start = 0;
		for (int i = l - kl; i >= 0; --i) {
			string ss = s.substr(i, kl);
			if (k >= stoi(ss, 0, 2)) {
				s_start = i;
				break;
			}
		}

		int ans = 0;
		// count 0 to s_start
		for (int i = 0; i < s_start; ++i) {
			if (s[i] == '0') ans++;
		}
		
		return ans + kl;
	}
};

int main() {
	char c;

	Solution sol;

	cout << sol.longestSubsequence("1001010", 5);


	cin >> c;

}