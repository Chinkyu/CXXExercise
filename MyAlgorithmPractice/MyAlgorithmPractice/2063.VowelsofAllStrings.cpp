// easy.. : from backward
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

// timeout .. 
class _Solution {
public:
	long long countVowels(string word) {
		int l = word.size();
		string vowls = "aeiou";

		long long ans = 0;
		for (int i = 0; i < l; ++i) {
			int vNum = 0;
			for (int j = i; j < l; ++j) {
				if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' ||
					word[j] == 'o' || word[j] == 'u') vNum++;
				ans += vNum;
			}
		}

		return ans;
	}
};

class Solution {
public:
	long long countVowels(string word) {
		int l = word.size();
		string vowls = "aeiou";

		long long ans = 0;
		long long vNum = 0;
		for (int i = l - 1; 0 <= i; --i) {
			if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' ||
				word[i] == 'o' || word[i] == 'u') {
				vNum += l - i;
			}
			ans += vNum;
		}

		return ans;
	}
};


int main() {
	char c;
	Solution sol;

	string word = "aba";

	cout << sol.countVowels(word);

	cin >> c;
}