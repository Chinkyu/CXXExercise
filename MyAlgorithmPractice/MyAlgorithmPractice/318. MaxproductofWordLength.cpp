#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool isDuplicate(string s1, string s2) {
		vector<bool> ckList(26, false);

		if (s1.size() == 0 || s2.size() == 0) return true;

		for (int i = 0; i < s1.size(); ++i) ckList[s1[i] - 'a'] = true;
		for (int i = 0; i < s2.size(); ++i) {
			if (ckList[s2[i]-'a'] == true) return true;
		}
		return false;
	}

	int maxProduct(vector<string>& words) {
		int l = words.size();

		if (l <= 0) return 0;
		vector<pair<int, int>> wIndex(l,make_pair(0, 0));

		for (int i = 0; i < l; ++i) {
			wIndex[i].first = words[i].size();
			wIndex[i].second = i;
		}

		sort(wIndex.begin(), wIndex.end());

		int max = 0;
		for (int i = l-1; i >= 0; --i) {
			for (int j = i-1; j >= 0; --j) {
				if (wIndex[i].first *wIndex[j].first > max) {
					if (!isDuplicate(words[wIndex[i].second], words[wIndex[j].second])) {
						int ans = wIndex[i].first * wIndex[j].first;
						//return (max > ans) ? max : ans;
						if (max < ans) max = ans;
					}
				}
			}
		}
		return max;
	}
};

int main() {
	char c;
	Solution sol;

	//vector<string> vs = { "abcw","baz","foo","bar","xtfn","abcdef" };
	//cout << sol.maxProduct(vs);

	//vector<string> vs = { "a","ab","abc","d","cd","bcd","abcd" };
	//cout << sol.maxProduct(vs);

	//vector<string> vs = { "a","aa","aaa","aaaa" };
	//cout << sol.maxProduct(vs);

	//vector<string> vs = { "abc", "a", "b", ""};
	//cout << sol.maxProduct(vs);

	vector<string> vs = {"a", "ab", "abc", "abcd", "abcde", "abcdef", "abcdefg", "abcdefgh", "abcdefghi", "abcdefghij", "abcdefghijk", "abcdefghijkl", "abcdefghijklm", "nopqrstuvwxyz", "mnopqrstuvwxyz", "lmnopqrstuvwxyz", "klmnopqrstuvwxyz", "jklmnopqrstuvwxyz", "ijklmnopqrstuvwxyz", "hijklmnopqrstuvwxyz", "ghijklmnopqrstuvwxyz", "fghijklmnopqrstuvwxyz", "efghijklmnopqrstuvwxyz", "defghijklmnopqrstuvwxyz", "cdefghijklmnopqrstuvwxyz", "bcdefghijklmnopqrstuvwxyz"
};
	cout << sol.maxProduct(vs);

	cin >> c;
}