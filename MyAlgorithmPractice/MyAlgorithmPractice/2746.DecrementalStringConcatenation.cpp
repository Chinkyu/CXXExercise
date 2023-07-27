// timeout  나는데..  Memoization  넣어야 한다는데... 
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
#include <cmath>

using namespace std;

// timeout  나는데..  Memoization  넣어야 한다는데... 
class Solution {
public:

	string join(string s1, string s2, bool &isMerged) {
		int sl = s1.size();
		isMerged = false;
		if (s1[sl - 1] == s2[0]) {
			s1.pop_back();
			isMerged = true;
		}
		return s1 + s2;
	}

	int min_len = INT_MAX;
	void traverse(vector<string> &words, int idx) {
	
		if (idx == words.size()) {
			min_len = min(min_len, (int)words[words.size() - 1].size());
			return;
		}
		
		string origin_word = words[idx];

		bool lc = false, rc = false;
		string ls = join(words[idx - 1], origin_word, lc);
		words[idx] = ls;
		traverse(words, idx + 1);

		string rs = join(origin_word, words[idx - 1], rc);
		words[idx] = rs;
		traverse(words, idx + 1);

		words[idx] = origin_word;
	}

	int minimizeConcatenatedLength(vector<string>& words) {
		min_len = INT_MAX;

		traverse(words, 1);

		return min_len;
	}
};

int main() {
	char c;

	Solution sol;

	//vector<string> words = { "aa", "ab", "bc" };
	vector<string> words = { "dh","gc","ddaf","aae","baeh","ige","dcg","bjja","dh","gbgf","gifif","d","jaaje","jcjh","cde","cg","afah","hjad" };
	cout << sol.minimizeConcatenatedLength(words);

	cin >> c;
}
