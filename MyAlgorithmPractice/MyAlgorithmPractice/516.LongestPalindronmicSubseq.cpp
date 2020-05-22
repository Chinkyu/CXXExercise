#include <iostream>
#include <vector>
#include <algorithm>

// C++ program of above approach 

using namespace std;

/*
class _Solution {
public:
	int LCS(string X, string Y, int n, int m) {
		int t[n + 1][m + 1];
		for (auto i = 0; i < n + 1; i++) {
			for (auto j = 0; j < m + 1; j++) {
				if (i == 0 || j == 0)
					t[i][j] = 0;
				else if (X[i - 1] == Y[j - 1])
					t[i][j] = t[i - 1][j - 1] + 1;
				else
					t[i][j] = max(t[i - 1][j], t[i][j - 1]);
			}
		}
		return t[n][m];
	}
	int longestPalindromeSubseq(string s) {
		std::string s1(s);
		std::reverse(s1.begin(), s1.end());
		int n = s.length();
		int m = s1.length();
		int lps = LCS(s, s1, n, m);
		return lps;
	}
};
*/

class LCSSolution {
public:
	int lcs(string &X, string &Y, int n, int m) {
		if (m == 0 || n == 0)
			return 0;

		if (X[m - 1] == Y[n - 1])
			return 1 + lcs(X, Y, m - 1, n - 1);
		else
			return max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));
	}

};
/* Driver program to test above functions */
int main() {
	char c;
	LCSSolution sol;
	string x = "AGGTAB";
	string y = "GXTXAYB";

	cout << sol.lcs(x, y, x.size(), y.size());
	cin >> c;
}

// This code is contributed 
// by Akanksha Rai 
