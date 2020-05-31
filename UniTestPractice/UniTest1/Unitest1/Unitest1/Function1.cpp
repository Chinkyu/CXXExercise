#include <iostream>
#include <vector>

using namespace std;

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

int main() {
	char c;
	Solution1 sol;

	cout << sol.isLarge(20);
	cin >> c;
}