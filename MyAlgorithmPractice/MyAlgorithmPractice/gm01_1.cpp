#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	long long getDecodeNumbers(string s) {
		int len = s.length();
		vector<long long> chkArray(len + 1);  // one more arrray for first item

		// 1st item 1
		chkArray[0] = 1;
		// 2nd item 0 -> 0
		if ('0' != s[0]) {
			chkArray[1] = 1;
		}
		else {
			chkArray[1] = 0;
		}

		for (int i = 2; i < len + 1; ++i) {

			// one digit
			if ('0' != s[i - 1]) {
				chkArray[i] = chkArray[i - 1];
			}

			// two digits
			int twoDigits = stoi(s.substr(i - 2, 2));
			//if (26 >= twoDigits) {
			if ((26 >= twoDigits) && (10 <= twoDigits)) {
				chkArray[i] += chkArray[i - 2];
			}
		}
		return chkArray[len];
	}
};

int main() {
	string line;
	Solution sol;
	while (getline(cin, line)) {
		cout << sol.getDecodeNumbers(line) << endl;
	}
}
