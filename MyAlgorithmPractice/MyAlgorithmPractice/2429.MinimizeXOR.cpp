//  Normal...  bitmasking...    SoSo.. 
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
	int minimizeXor(int num1, int num2) {

		// count  of num2
		int cnum2 = 0;
		while (num2 > 0) {
			cnum2 += num2 % 2;
			num2 /= 2;
		}

		// count of num1
		int tnum1 = num1;
		int cnum1 = 0;
		while (tnum1 > 0) {
			cnum1 += tnum1 % 2;
			tnum1 /= 2;
		}

		if (cnum1 == cnum2) {
			return num1;
		}
		else if (cnum1 > cnum2) {
			// remove last cnum1 - cnum2;
			int oneremovecount = cnum1 - cnum2;
			for (int i = 0; oneremovecount > 0; ++i) {
				int mask = 0x01 << i;
				if ((num1 & mask) == mask) {
					num1 ^= mask;
					oneremovecount--;
				}
			}
			return num1;

		}
		else {  // cnum1 < cnum2
			// add 1 last cnum2 - cnum1
			int oneaddcount = cnum2 - cnum1;
			for (int i = 0; oneaddcount > 0; ++i) {
				int mask = 0x01 << i;
				if ((num1 & mask) == 0) {
					num1 |= mask;
					oneaddcount--;
				}
			}
			return num1;
		}

	}
};

int main() {
	char c;

	Solution sol;

	cout << sol.minimizeXor(79, 74);

	cin >> c;
}