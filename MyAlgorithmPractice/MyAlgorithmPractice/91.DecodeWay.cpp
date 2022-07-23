#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

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

// recursive memoization from answer reference
class Solution2m {
public:
	unordered_map<int, int> m;

	int findDecodeNumber(int idx, string &iString) {
		int ans = 0;
		int len = iString.length();

		// Hit Cache
		if (m.find(idx) != m.end()) {
			return m[idx];
		}

		// idx exceed length count 1
		if (idx >= len - 1) {
			return 1;
		}

		// if '0' it can't be decoded
		if ('0' == iString[idx]) return 0;

		// Always more than two number
		int n1 = iString[idx] - '0';

		ans += findDecodeNumber(idx + 1, iString);

		//int n2 = (iString[idx] - '0') * 10 + (iString[idx + 1] - '0');
		if (26 >= stoi(iString.substr(idx, 2))) {
			ans += findDecodeNumber(idx + 2, iString);
		}

		m[idx] = ans;
		return ans;
	}

	int numDecodings(string s) {

		return findDecodeNumber(0, s);

	}
};


// DP solution
class Solution3m {
public:
	int numDecodings(string s) {
		int len = s.length();
		vector<int> dp(len + 1);  // 1 more dp array

		dp[0] = 1;
		dp[1] = s[0] != '0' ? 1 : 0; // if first number is 0 -> 0

		for (int i = 2; i < len + 1; ++i) {

			// single
			if ('0' != s[i - 1]) dp[i] = dp[i - 1];

			// double
			int twoDigit = stoi(s.substr(i - 2, 2));
			if ((26 >= twoDigit) && (10 <= twoDigit)) {
				dp[i] += dp[i - 2];
			}
		}

		return dp[len];
	}

};


int main() {
	int i;
	char c;

//	Solution1_Timeout s1;
//	Solution2_Timeout s2;
	Solution1m s1m;
	Solution2m s2m;
	Solution3m s3m;

//	cout << s1.numDecodings("111111111111111111111111111111111111111111111") << endl;
//	cout << s2.numDecodings("11111111111111111111111111") << endl;
	cout << s1m.numDecodings("111111111111111111111111111111111111111111111") << endl;
	cout << s2m.numDecodings("111111111111111111111111111111111111111111111") << endl;
	cout << s3m.numDecodings("111111111111111111111111111111111111111111111") << endl;

	cin >> c;
}


// Normal Recursive method  -> timeout
class Solution1_timeout {
public:
	int ans = 0;

	void findDecodeNumber(int sti, string &iString) {
		int edi = iString.length() - 1;

		if (sti >= edi && iString[sti] != '0') {   // if sti == endi, doesn't need cound only one way
			ans++;
			return;
		}

		// Always more than two number
		int n1 = iString[sti] - '0';
		// escapt '0'
		if (0 == n1) return;
		findDecodeNumber(sti + 1, iString);

		int n2 = (iString[sti] - '0') * 10 + (iString[sti + 1] - '0');
		if (26 >= n2) {
			findDecodeNumber(sti + 2, iString);
		}
	}

	int numDecodings(string s) {

		ans = 0;
		findDecodeNumber(0, s);

		return ans;
	}
};

// Normal Quieu method  - can not use memoization
class Solution2_Timeout {
public:

	int findDecodeNumber(string &iString) {
		int edIdx = iString.length() - 1;
		queue<int> idxQ;
		int ans = 0;

		idxQ.push(0);
		while (!idxQ.empty()) {
			int i = idxQ.front();
			idxQ.pop();

			if (i >= edIdx && iString[i] != '0') {  // End index  count up
				ans++;
				continue;
			}

			// assert : if (i +1 <= edIdx ) 
			// this number
			if ('0' == iString[i]) continue;
			idxQ.push(i + 1);

			if ((i + 1 <= edIdx)
				&& (26 >= (iString[i] - '0') * 10 + (iString[i + 1] - '0'))) {
				idxQ.push(i + 2);
			}

		}

		return ans;
	}

	int numDecodings(string s) {

		return findDecodeNumber(s);

	}
};


