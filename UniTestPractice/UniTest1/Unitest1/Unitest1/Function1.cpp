#include <iostream>
#include <vector>
#include "Function1.h"

using namespace std;

/*
class Solution1 {
public:
	int tHold = 10;

	bool isLarge(int x) {
		if (x > tHold) {
			return true;
		}
		else {
			return false;
		}
	}
};
*/

bool Solution1::isLarge(int x) {
	if (x > tHold) {
		return true;
	}
	else {
		return false;
	}
}

#define TEN 10
bool isLargeThan10(int x) {
	if (x > TEN) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	char c;
	Solution1 sol;

	cout << sol.isLarge(20);
	cin >> c;
}