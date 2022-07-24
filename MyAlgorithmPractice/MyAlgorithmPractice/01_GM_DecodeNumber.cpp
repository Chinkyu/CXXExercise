#include <iostream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

// DP solution
class Solution3m {
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
	int i;
	char c;
//	Solution1 s1;
//	Solution2 s2;
	Solution3m s3m;

//	cout << s1.getDecodeNumber() << endl;
//	cout << s2.getDecodeNumber() << endl;
	cout << s3m.getDecodeNumber("111111111111111111111111111111111111") << endl;


	cin >> c;
}





#if 0    // bruteforce recursive  - timeout
class Solution1 {
public:
	int ans = 0;

	void findDecodeNumber(int sti, string &iString) {
		int edi = iString.length() - 1;

		if (sti >= edi) {   // if sti == endi, doesn't need cound only one way
			ans++;
			return;
		}

		// Always more than two number
		int n1 = iString[sti] - '0';
		findDecodeNumber(sti + 1, iString);

		int n2 = (iString[sti] - '0') * 10 + (iString[sti + 1] - '0');
		if (26 >= n2) {
			findDecodeNumber(sti + 2, iString);
		}
	}

	int getDecodeNumber() {
		string iString;

		getline(cin, iString);

		ans = 0;
		findDecodeNumber(0, iString);

		return ans;
	}
};

class Solution2 {
public:
	int ans = 0;

	void findDecodeNumber(string &iString) {
		int edIdx = iString.length() - 1;
		queue<int> idxQ;

		idxQ.push(0);
		while (!idxQ.empty()) {
			int i = idxQ.front();
			idxQ.pop();

			if (i >= edIdx) {  // End index  count up
				ans++;
				continue;
			}

			// assert : if (i +1 <= edIdx ) 
			// this number
			idxQ.push(i + 1);

			if ((i + 1 <= edIdx)
				&& (26 >= (iString[i] - '0') * 10 + (iString[i + 1] - '0'))) {
				idxQ.push(i + 2);
			}

		}
	}

	int getDecodeNumber() {
		string iString;

		getline(cin, iString);

		ans = 0;
		findDecodeNumber(iString);

		return ans;
	}
};


#endif

