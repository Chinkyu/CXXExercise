#include <iostream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

// DP solution
class Solution {
public:
	int getDecodeNumber(string s) {
		int len = s.length();
		vector<int> chkArray(len + 1);  // 1 more dp array

		chkArray[0] = 1;
		//chkArray[1] = s[0] != '0' ? 1 : 0; // if first number is 0 -> 0
		if ('0' != s[0]) {
			chkArray[1] = 1;
		}
		else {
			chkArray[1] = 0;
		}

		for (register int i = 2; i < len + 1; ++i) {

			// One digit
			if ('0' != s[i - 1]) {
				chkArray[i] = chkArray[i - 1];
			}

			// Two digit
			int twoDigit = stoi(s.substr(i - 2, 2));
			if ((26 >= twoDigit) && (10 <= twoDigit)) {
				chkArray[i] += chkArray[i - 2];
			}
		}

		return chkArray[len];
	}

};



int main() {
	Solution sol;
	string input;
	char c;

	getline(cin, input);

	cout << sol.getDecodeNumber(input);

	cin >> c;
}
