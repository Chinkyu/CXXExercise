#include <iostream>
#include <cmath>

using namespace std;

class _Solution {
public:
    bool judgeSquareSum(int c) {
		for (long a = 0; a * a <= c; a++) {
			for (long b = 0; b * b <= c; b++) {
				if (a * a + b * b == c)
					return true;
			}
		}
		return false;
    }
};

class Solution {
public:
	bool judgeSquareSum(int c) {
		for (long a = 0; a * a <= c; a++) {
			double b = sqrt(c - a * a);
			if (b == (int)b) return true;
		}
		return false;
	}
};