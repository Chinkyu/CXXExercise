// easy .
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
	bool inline isVowel(char c) {
		return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ? true : false;
	}
	int maxVowels(string s, int k) {
		int ans = 0;
		int l = s.size();

		k = min(l , k);
		int cNum = 0;
		for (int i = 0; i < k; ++i) {
			if(isVowel(s[i])) cNum++;
		}
		ans = cNum;

		for (int i = 0, j = k; j < l; ++i, ++j) {
			if (isVowel(s[i])) cNum--;
			if (isVowel(s[j])) cNum++;
			ans = max(ans, cNum);
		}
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	string s = "weallloveyou"; //  "abciiidef";
	cout << sol.maxVowels(s, 7);

	cin >> c;
}