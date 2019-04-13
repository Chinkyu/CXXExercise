#include <iostream>

using namespace std;

class Solution {
public:
	double _myPow(double x, int n) {
		return pow(x, n);
	}

	double myPow(double x, int n) {
		double rel = 1.0;
		bool isNMinus = false;
		long long ln = n;

		if (x == 1) return 1;

		if (ln < 0) {
			ln *= -1;
			isNMinus = true;
		}
		else if (ln == 0) {
			return 1.0;
		}
		else if (ln == 1) {
			return x;
		}
		else if (ln == 2) {
			return x * x;
		}

// try 1
//		for (int i = 0; i < n; ++i) {
//			rel *= x;
//		}

// try 2
		//long long i;
		//rel = x;
		//for (i = 2; i < ln; i = i * 2) {
		//	rel = rel * rel;
		//}

		//for (long long j = i / 2; j < ln; ++j) {
		//	rel *= x;
		//}

// try 3

		rel = myPow(x, ln / 2);// *myPow(x, ln - ln / 2);
		rel = rel * rel;
		if (ln % 2 == 1 || ln % 2 == -1) rel *= x;

		if (isNMinus == true) rel = 1 / rel;
		return rel;
	}
};

class Solution2 {
public:
	double myPow(double x, int n) {
		if (fabs(x) <= 0.000001 && n < 0) {//
			throw new string("x can't be 0!");
		}
		else if (fabs(x) <= 0.000001 &&  n > 0) {
			return 0;
		}
		if (n == 0) {
			return 1;
		}
		double temp = myPow(x, n / 2);
		if (n % 2 == 1 || n % 2 == -1) {
			return (n > 0 ? temp * temp*x : 1 / x * temp*temp);
		}
		return temp * temp;
	}
};

int main() {
	Solution sol;
	Solution2 sol2;
	char c;

	//cout << sol.myPow(2.000000, -2);
	//cout << sol.myPow(2.000000, 10);
	//cout << sol.myPow(0.00001, 2147483647);
	cout << sol.myPow(2.0, -2147483646);
//	cout << sol2.myPow(2.0, -2147483646);

	cin >> c;
}