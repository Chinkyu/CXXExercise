// 답봤음... count array를 가지고 시도 할려고 했던것이 잘못이었음... 
// 없이 간단하게 풀리는데..... 생각 하기 쉽지 않아 보임. 
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
	int longestSemiRepetitiveSubstring_v1(string s) {
		vector<int> cnt(10, 0); // count variable
		int l = s.size();
		int two_idx = -1;
		int st = 0, ed = 0;
		int max_len = 0;

		while (ed < l) {
			if (two_idx == -1) {
				cnt[s[ed]-'0']++;
				if (cnt[s[ed]-'0'] == 2) two_idx = s[ed] - '0';
				ed++;
			}
			else if (two_idx != -1) {
				if ( 2 <= cnt[s[ed]-'0'] + 1) {  // if it increase new or exisiing to 3
					cnt[s[st]-'0']--;
					if (s[st] - '0' == two_idx && cnt[s[st]-'0'] <= 1) two_idx = -1;
					st++;
				}
				else {
					cnt[s[ed] - '0']++;
					ed++;
				}
			}

			max_len = max(max_len, ed - st);
		}

		return max_len;
	}


	int longestSemiRepetitiveSubstring(string s) {
		//vector<int> cnt(10, 0); // count variable
		int l = s.size();
		int two_cnt = 0, two_val = -1;
		int st = 0, ed = 0;
		int max_len = 0;

		while (ed < l) {
			if (ed > 0 && s[ed] == s[ed - 1]) two_cnt++;

			// identify 1st two
			if (two_cnt == 1 && s[ed] == s[ed - 1]) two_val = s[ed];

			if (two_cnt > 1) {
				while (st <= ed && two_cnt > 1) {
					if (s[st] == s[st+1] && s[st] == two_val) two_cnt--;
					st++;
				}
				two_val = s[ed];
			}

			max_len = max(max_len, ed - st + 1);
			ed++;
		}

		return max_len;
	}

};

int main() {
	char c;

	Solution sol;

	string s = "0010";// "5494"; // "52233";
	cout << sol.longestSemiRepetitiveSubstring(s);
	//cout << sol.longestString(3, 25, 48);

	cin >> c;
}
