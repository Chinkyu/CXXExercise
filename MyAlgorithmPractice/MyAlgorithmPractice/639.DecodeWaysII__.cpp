#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int ans;
	unordered_map<string, int> m;

	int getDecodeNumber(int i, string &str) {
		int len = str.length();
		int subAns = 0;

		// if there is in map.. return that and return 
		if (m.find(str.substr(i)) != m.end()) {
			return m[str.substr(i)];
		}

		if (i >= len) return 1;
		
		// one number 
		if (str[i] == '0') return 0;
		subAns += getDecodeNumber(i + 1, str);

		// two number
		if (i + 1 < len) {
			int n2 = (str[i] - '0') * 10 + (str[i + 1] - '0');
			if (10 <= n2 && n2 <= 26) {
				subAns += getDecodeNumber(i + 2, str);
			}
		}
		
		m[str.substr(i)] = subAns;
		return subAns;
	}

	unordered_map<string, int> m2;
	void numRecursion(int idx, string &inStr, string beStr) {

		if (idx == inStr.length()) {
			ans += getDecodeNumber(0, beStr);
			return;
		}

		if (inStr[idx] == '*') {
			for (int i = 1; i <= 9; ++i) {
				string nStr = beStr;
				nStr.push_back('0' + i);
				numRecursion(idx + 1, inStr, nStr);
			}
		}
		else {
			beStr.push_back(inStr[idx]);
			numRecursion(idx + 1, inStr, beStr);
		}
	}

	int numDecodings(string s) {
		ans = 0;
		string tStr = "";
		numRecursion(0, s, tStr);

		return ans;
	}
};


int main() {
	char c;
	Solution s;

	string str = "26";

	//cout << s.getDecodeNumber(0, str) << endl;
	cout << s.numDecodings("2*") << endl;

	cin >> c;
}