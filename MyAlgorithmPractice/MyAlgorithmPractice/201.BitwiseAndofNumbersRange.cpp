#include <iostream>

using namespace std;

// from explanation 
class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {

		if ((m & n) == 0) { return 0; }

		int aLow = m;
		int aHigh = n;
		int aShiftCount = 0;

		while (aLow != aHigh) {
			aLow = aLow >> 1;
			aHigh = aHigh >> 1;
			aShiftCount += 1;
		}

		return (aHigh << aShiftCount);
	}
};

// timeout solution 
class _Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
		int res = m;
		for (int i = m; i <= n; ++i) {
			if (i == 0) return 0;
			res &= i;
		}
		return res;
    }
};


int main() {


}
