#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

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


class Solution1m {
public:
	unordered_map<string, int> m;

	int findDecodeNumber(int sti, string &iString) {
		int ans = 0;
		int edi = iString.length() - 1;

		if (sti >= edi && iString[sti] != '0') {   // if sti == endi, doesn't need cound only one way
			return 1;
		}

		// if '0' it can't be decoded
		if ('0' == iString[sti]) return 0;

		// Always more than two number
		int n1 = iString[sti] - '0';

		if (m.find(iString.substr(sti + 1)) != m.end()) {
			ans += m[iString.substr(sti + 1)];
		}
		else {
			int subAns = findDecodeNumber(sti + 1, iString);
			ans += subAns;
			m[iString.substr(sti + 1)] = subAns;
		}

		int n2 = (iString[sti] - '0') * 10 + (iString[sti + 1] - '0');
		if (26 >= n2) {
			if (m.find(iString.substr(sti + 2)) != m.end()) {
				ans += m[iString.substr(sti + 2)];
			}
			else {
				int subAns = findDecodeNumber(sti + 2, iString);
				ans += subAns;
				m[iString.substr(sti + 2)] = subAns;
			}
		}

		return ans;
	}

	int numDecodings(string s) {

		return findDecodeNumber(0, s);

	}
};

int main() {
	string line;
	Solution sol;
	Solution1m sol1m;

	while (getline(cin, line)) {
		cout << sol.getDecodeNumbers(line) << endl;
		cout << sol1m.findDecodeNumber(0, line) << endl;
	}
}
