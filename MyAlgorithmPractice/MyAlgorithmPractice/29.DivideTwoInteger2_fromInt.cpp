// ���� �� �˰����� ���� ���ư��� �˰����� �߰� Ȯ�� �� �� �ʿ� ����. 
// ���� �����ϴ�  ������ ������ �����  Timeout �߻���. 


#include <iostream>

using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 1) return dividend;
		if (divisor == -1) {
			if (dividend == INT32_MIN) return INT32_MAX;
			return -dividend;
		}
		if (divisor == INT32_MIN) {
			switch (dividend) {
			case INT32_MIN: return 1;
			default: return 0;
			}
		}
		// dividend / divisor
		bool minus = (dividend < 0) ^ (divisor < 0);

		// let dividend be negative to store more digits
		if (dividend > 0)
			dividend = -dividend;

		if (divisor < 0)
			divisor = -divisor;

		int res = 0;
		int u = 1;

		while (dividend <= -divisor) {
			dividend += divisor;
			res += u;
			if (divisor & (1 << 30)) break; // divisor will be overflow
			divisor <<= 1;
			u <<= 1;
		}
		while (divisor > 0) {
			if (dividend <= -divisor) {
				dividend += divisor;
				res += u;
			}
			divisor >>= 1;
			u >>= 1;
		}

		return minus ? -res : res;
	}
};

int main() {
	char c;
	Solution sol;

	cout << sol.divide(100, 3);

	cin >> c;
}