// 문제 이상해서 그냥 답보고  skip
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


class Solution {
	// O(INT_MAX / 2) time -> TLE
	int findIntegerTraverse(int k, int digit1, int digit2) {
		if (k == 1) {
			// answer >= 2
			int d1 = min(digit1, digit2);
			int d2 = max(digit1, digit2);
			if (d2 < 2) {
				// 11 or 10, -1 for 00
				return d2 > 0 ? 10 * d2 + d1 : -1;
			}

			return d1 >= 2 ? d1 : d2;
		}

		long long num = k + k;
		for (; num <= INT_MAX; num += k) {
			long long copy = num;
			while (copy > 0) {
				int d = copy % 10;
				// break copy > 0
				if (d != digit1 && d != digit2) {
					break;
				}

				copy /= 10;
			}

			if (copy == 0) {
				return num;
			}
		}

		return -1;
	}
public:
	/*
	Observations:
	1. Generate numbers in an organized way. The answer should stay
	   in range [2k, INT_MAX], has a maximum of 10 digits.

	   when digit1 != digit2 total number to consider is 2^10, since
	   at each digit we have 2 choices.

	   when one of them is 0, total = 1 * 2^9, sicne the first
	   digit cannot be 0.

	   when digit1 == digit2, total = 1 (1+1+...+1 but equivalent to 1)

	   when both 0, total = 1 (only 0 itself)
	2. Enumerate all numbers formed by digit1 and digit2, with the
	   help of a queue. Be careful with overflow when generate the
	   next number.

	   enumeration; bfs; queue;
	   O(2^10) -> O(1) time and space.
	*/
	int findInteger(int k, int digit1, int digit2) {
		// return findIntegerTraverse(k, digit1, digit2);
		int d1 = min(digit1, digit2);
		int d2 = max(digit1, digit2);

		queue<int> q;
		q.push(d1);
		if (d2 != d1) {
			q.push(d2);
		}

		while (!q.empty()) {
			int x = q.front(); q.pop();
			if (x > k && x % k == 0) {
				return x;
			}

			if (x == 0) {
				continue;
			}

			long long next = 10LL * x + d1;
			if (next <= INT_MAX) {
				q.push(next);

				next += d2 - d1;
				if (d2 != d1 && next <= INT_MAX) {
					q.push(next);
				}
			}
		}

		return -1;
	}
};

class _Solution {
public:
	int findInteger(int k, int digit1, int digit2) {
		int d1 = digit1 * 10 + digit2;
		int d2 = digit2 * 10 + digit1;
		int d3 = digit1 * 10 + digit1;
		int d4 = digit2 * 10 + digit2;

		int ans = INT_MAX;
		if (digit1 > k && digit1 % k == 0) ans = digit1;
		if (digit2 > k && digit2 % k == 0) ans = min(ans, digit2);
		if (d1 > k && d1 % k == 0) ans = min(ans, d1);
		if (d2 > k && d2 % k == 0) ans = min(ans, d2);
		if (d3 > k && d3 % k == 0) ans = min(ans, d3);
		if (d4 > k && d4 % k == 0) ans = min(ans, d4);

		return (ans == INT_MAX) ? -1 : ans;
	}
};

int main() {
	char c;
	Solution sol;

	cout << sol.findInteger(2, 0, 2);

	cin >> c;
}