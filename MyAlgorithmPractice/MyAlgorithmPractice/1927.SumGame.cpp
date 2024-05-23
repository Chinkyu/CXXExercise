// 답봤음...  math problem  이라는구만... 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	bool sumGame(string s) {
		double res = 0, n = s.length();
		for (int i = 0; i < n; ++i)
			res += (i < n / 2 ? 1 : -1) * (s[i] == '?' ? 4.5 : s[i] - '0');
		return res != 0.0;
	}
	bool _sumGame(string num) {
		int l = num.size();
		int lq = 0, rq = 0;
		int ls = 0, rs = 0;

		for (int i = 0; i < l / 2; ++i) {
			if (num[i] != '?') {
				ls += num[i] - '0';
			}
			else {
				lq++;
			}

			if (num[l - i - 1] != '?') {
				rs += num[l - i - 1] - '0';
			}
			else {
				rq++;
			}
		}

		int gap = abs(ls - rs);

		int p_gap = 0;
		if (lq > rq) {
			p_gap += rq * 8;
			p_gap += (lq - rq) * 9;
		}
		else if (lq < rq) {
			p_gap += lq * 8;
			p_gap += (rq - lq) * 9;

		}
		else {  // lq == rq
			p_gap += lq * 8;
		}

		return (gap <= p_gap) ? true : false;
	}
};

int main() {
	char c;
	Solution sol;

	string num = "?3295???";

	cout << sol.sumGame(num);

	cin >> c;
}