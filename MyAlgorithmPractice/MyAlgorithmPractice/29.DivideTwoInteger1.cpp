#include <iostream>

using namespace std;

// -2^32 ~ 2^32 -1  
// 2^32 == 4,294,967,286


class Solution {
public:
	int divide(int dividend, int divisor) {
		int i, j;
		int num_dividend = 0, num_divisor = 0;
		int res = 0;
		int isMinus = 1;

		long long did = dividend;
		long long dis = divisor;

		if (did < 0) {
			isMinus *= -1;
			did *= -1;
		}
		if (dis < 0) {
			isMinus *= -1;
			dis *= -1;
		}

		// increase speed 
		if (dis == 1) {
			if (did > pow(2, 31) - 1 && isMinus != -1) did = pow(2, 31) - 1;
			return did * isMinus;
		}
	

		// find number of digit
		int temp = did;
		for (i = 0, num_dividend = 0; temp >= 10; ++i) {
			temp /= 10;
			num_dividend++;
		}
		temp = dis;
		for (i = 0, num_divisor = 0; temp >= 10; ++i) {
			temp /= 10;
			num_divisor++;
		}

		int dif = num_dividend - num_divisor;
		if (dif < 0) return 0;

		for (i = dif; i >= 0; --i) {
			for (j = 0; did >= dis*pow(10,i); ++j) {
				did -= dis * pow(10, i);
			}
			res += j * pow(10, i);
		}

//		cout << res;
		if (res > pow(2, 31) - 1 && isMinus != -1) res = pow(2, 31) - 1;
		return res * isMinus;
	}
};

int main() {
	char c;
	Solution sol;

	cout << sol.divide(-2147483647, -1);

	cin >> c;
}