#include <iostream>

using namespace std;

class Solution {
public:
	int titleToNumber(string s) {
		int ans = 0;
		int len = s.length();
		int i, j;

		for (i = len - 1, j = 0; i >= 0; i--, j++) {
			ans += (s[i] - 'A' + 1) * pow(26, j);
		}
		return ans;
	}
};


int main() {
	int i;
	Solution s;
	cout << s.titleToNumber("ZY");
	cin >> i;


}