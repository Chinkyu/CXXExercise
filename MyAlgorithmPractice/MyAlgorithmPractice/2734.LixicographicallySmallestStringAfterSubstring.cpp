// a 가지고 확인... exception처리하는데 시간이 좀 걸림.. 
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

class Solution {
public:
	string smallestString(string s) {
		int l = s.size(), st = 0, ed = l;

		//if (s == "a") return "z";

		int status = 0; // start state
		for (int i = 0; i < l; ++i) {

			switch (status) {
			case 0: // start state 
				if (s[i] == 'a') continue;
				status = 1;
				st = i;
				break;
			case 1 : // after_start_check_status
				if (s[i] == 'a') {
					status = 2;
					ed = i;
				}
				break;
			}
		}

		if (ed > st) {

			// if all a
			if (st == 0 && ed == l && s[0] == 'a') {
				s[l - 1] = 'z';
				return s;
			}

			for (int i = st; i < ed; ++i) {
				if (s[i] == 'a') {
					s[i] = 'z';
				}
				else {
					s[i]--;
				}
			}
		}

		return s;
	}
};

int main() {
	char c;

	Solution sol;

	string s = "aa"; // "leetcode"; // "acbbc";// "cbabc";
	cout << sol.smallestString(s);
	//cout << sol.longestString(3, 25, 48);

	cin >> c;
}
