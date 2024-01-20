// ¥‰∫√Ωø  -  ≈∏¿”æ∆øÙ¿Ã∂Û : bitmask∏¶ ªÁøÎ«—≥¿Ã ¿Ã±Ë.. 
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
	int wordCount(vector<string>& startWords, vector<string>& targetWords) {
		// generates hashes for startWords.
		unordered_set<int> vis;
		for (string s : startWords) {
			int hash = 0;
			for (int i = 0; i < s.size(); i++) {
				hash += (1 << (s[i] - 'a'));
			}
			vis.insert(hash);
		}

		// check each target Word
		int res = 0;
		for (string s : targetWords) {
			int hash = 0;
			// k is the index of character we remove
			for (int k = 0; k < s.size(); k++) {
				hash = 0;
				for (int i = 0; i < s.size(); i++) {
					if (i == k) continue;
					hash += (1 << (s[i] - 'a'));
				}
				if (vis.count(hash)) {
					res++;
					break;
				}
			}
		}

		return res;
	}
};
// timeout.. 
class Solution {
public:
	int wordCount(vector<string>& startWords, vector<string>& targetWords) {
		// remove duplicate of startWords
		set<string> startSet;
		for (auto &it : startWords) startSet.insert(it);
		startWords.clear();
		for (auto &it : startSet) startWords.push_back(it);

		int sl = startWords.size(), el = targetWords.size();

		vector<unordered_map<char, int>> sv(sl, unordered_map<char, int>());
		vector<unordered_map<char, int>> ev(el, unordered_map<char, int>());

		for (int i = 0; i < sl; ++i) {
			for (auto jt : startWords[i]) sv[i][jt]++;
		}

		for (int i = 0; i < el; ++i) {
			for (auto jt : targetWords[i]) ev[i][jt]++;
		}

		int ans = 0;

		for (int i = 0; i < el; ++i) { // target
			for (int j = 0; j < sl; ++j) { // start
				if (targetWords[i].size() != startWords[j].size() + 1) continue;

				bool isAllSame = true;
				// check all start num 
				for (auto &it : sv[j]) {
					if (ev[i][it.first] != sv[j][it.first]) {
						isAllSame = false;
						break;
					}
				}

				if (isAllSame == true && targetWords[i].size() == startWords[j].size()+ 1) {
					ans++;
					break;
				}
			}
		}
		
		return ans;
	}
};

int main() {
	char c;

	Solution sol;
	vector<string> st = { "ant", "act", "tack" };
	vector<string> ed = { "tack", "act", "acti" };

	cout << sol.wordCount(st, ed);

	cin >> c;
}