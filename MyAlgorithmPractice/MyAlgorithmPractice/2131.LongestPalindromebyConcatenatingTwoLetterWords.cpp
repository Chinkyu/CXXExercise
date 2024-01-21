// easy : by counting...  same char , diff char .. 
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
	int longestPalindrome(vector<string>& words) {
		int sameNum = 0;
		int pairNum = 0;

		unordered_map<string, int> m;

		for (auto &it : words) {
			m[it]++;
		}

		bool isCenter = false;
		int num = 0;
		for (auto &it : m) {
			if (it.first[0] == it.first[1]) {  // if it is same character 
				if (it.second % 2 == 1) isCenter = true;

				num += (it.second/2) * 4;
			}
			else {								// different character
				string st;
				st.push_back(it.first[1]);
				st.push_back(it.first[0]);
				if (m.find(st) != m.end()) {   // if exist palindrome string
					// get min of both and make them zero
					num += min(it.second, m[st]) * 4;
					it.second = 0;
					m[st] = 0;
				}
			}

		}

		num = (isCenter == true) ? num + 2: num;
		return num;
	}
};

int main() {
	char c;

	Solution sol;
	vector<string> words = { "lc", "cl", "gg" };

	cout << sol.longestPalindrome(words);

	cin >> c;
}