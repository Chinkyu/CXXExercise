#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int gcd(int a, int b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

	string fractionAddition(string expression) {
		istringstream in(expression);
		int A = 0, B = 1, a, b;
		char _;
		while (in >> a >> _ >> b) {
			A = A * b + a * B;
			B *= b;
			int g = abs(gcd(A, B));
			A /= g;
			B /= g;
		}
		return to_string(A) + '/' + to_string(B);
	}
};

int main() {
	char c;
	Solution sol;

	cout << sol.fractionAddition("-1/2+1/2");

	cin >> c;
}

