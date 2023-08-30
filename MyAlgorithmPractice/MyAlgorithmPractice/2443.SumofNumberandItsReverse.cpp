//  Brute force  works OK 
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
	bool _isReverse(int n1, int n2) {
		string s1, s2;

		s1 = to_string(n1);
		s2 = to_string(n2);

		int l1 = s1.size(), l2 = s2.size();
		int lmin = min(l1, l2);

		for (int i = 0; i < lmin; ++i) {
			if (l1 > l2) {
				if (s1[i] != s2[l2 - i - 1]) return false;
			}
			else if (l2 >= l1) {
				if (s2[i] != s1[l1 - i - 1]) return false;
			}
		}
		return true;
	}

	bool isReverse(int n1, int n2) {
		string s1, s2;

		s1 = to_string(n1);
		s2 = to_string(n2);

		int l1 = s1.size(), l2 = s2.size();
		int lmax = max(l1, l2);

		if (l1 < lmax) {
			string ts1 = s1;
			s1 = string( lmax - l1, '0');
			s1.append(ts1);
		}
		if (l2 < lmax) {
			string ts2 = s2;
			s2 = string('0', lmax - l1);
			s2.append(ts2);
		}

		for (int i = 0; i < lmax; ++i) {
			if (s1[i] != s2[l2 - i - 1]) return false;
		}
		return true;
	}


	bool sumOfNumberAndReverse(int num) {
		bool ans = false;

		if (num == 0) return true;

		for (int i = 1; i <= num / 2; ++i) {
			if (isReverse(i, num - i)) return true;
		}
		return false;
	}
};

int main() {
	char c;

	Solution sol;

	cout << sol.sumOfNumberAndReverse(0);

	cin >> c;
}