// 슬라이딩 윈도우로 했는데... 디버깅에 시간이 좀 걸림
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
	int numberOfSpecialSubstrings(string s) {
		int l = s.size();

		vector<int> cnt(26, 0);
		int cnt_num = 0;
		int ed = l;
		int num = 0;
		// Make initial substring 
		
		for (int i = 0; i < l; ++i) {
			if (cnt[s[i] - 'a'] > 0) {
				//num += i;  // add count
				ed = i;
				break;
			}
			cnt[s[i] - 'a']++;
			cnt_num++;
		}
		num += cnt_num;

		for (int i = 1; i < l; ++i) {
			// XXXX : do we need special handing when i == ed ???? 

			cnt[s[i - 1] - 'a']--;
			cnt_num--;
			//num += cnt_num;

			for (int j = ed; j < l; ++j) {
				ed = l;
				if (cnt[s[j] - 'a'] > 0) {
					// end of substring 
					//num += j - j;
					ed = j;
					break;
				}
				cnt[s[j] - 'a']++;
				cnt_num++;
			}
			num += cnt_num;
		}

		return num;
	}
};

int main() {
	char c;

	Solution sol;

	string s = "abab"; //"ooo"; //  "abcd";
	cout << sol.numberOfSpecialSubstrings(s);
	//cout << sol.longestString(3, 25, 48);

	cin >> c;
}
