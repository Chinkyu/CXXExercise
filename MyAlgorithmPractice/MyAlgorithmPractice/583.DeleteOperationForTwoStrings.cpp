// solving with longest common substring 


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:

	int LCSubStr(string X, string Y)
	{
		int m = X.size()-1, n = Y.size()-1;

		// Create a table to store lengths of longest 
		// common suffixes of substrings. Note that 
		// LCSuff[i][j] contains length of longest 
		// common suffix of X[0..i-1] and Y[0..j-1]. 

		//int LCSuff[m + 1][n + 1];

		vector<vector<int>> LCSuff(m+1, vector<int>(n+1, 0));

		int result = 0; // To store length of the 
						// longest common substring 

		/* Following steps build LCSuff[m+1][n+1] in
			bottom up fashion. */
		for (int i = 0; i <= m; i++)
		{
			for (int j = 0; j <= n; j++)
			{

				// The first row and first column 
				// entries have no logical meaning, 
				// they are used only for simplicity 
				// of program 
				if (i == 0 || j == 0)
					LCSuff[i][j] = 0;

				else if (X[i - 1] == Y[j - 1])
				{
					LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
					result = max(result, LCSuff[i][j]);
				}
				else LCSuff[i][j] = 0;
			}
		}
		return result;
	}

	int LCSubStr2(string text1, string text2) {
		int n = text1.length();
		int m = text2.length();
		if (n == 0 || m == 0)
			return 0;
		//int dp[n + 1][m + 1];
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
		for (int i = 0; i < n + 1; i++) {
			for (int j = 0; j < m + 1; j++) {
				if (i == 0 || j == 0)
					dp[i][j] = 0;
			}
		}
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				if (text1[i - 1] == text2[j - 1])
					dp[i][j] = 1 + dp[i - 1][j - 1];
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		return dp[n][m];
	}

	int minDistance(string word1, string word2) {

		int lcs = LCSubStr2(word1, word2);

		return ((word1.size() - lcs) + (word2.size() - lcs));
	}
};

int main()
{
	char c;
	Solution sol;

	string s1 = "sea", s2 = "eat";

	cout << sol.minDistance(s1, s2);

	cin >> c;
}


#if 0
/* Dynamic Programming solution to find length of the
longest common substring */
#include<iostream> 
#include<string.h> 
using namespace std;

/* Returns length of longest common substring of X[0..m-1]
and Y[0..n-1] */
int LCSubStr(char *X, char *Y, int m, int n)
{
	// Create a table to store lengths of longest 
	// common suffixes of substrings. Note that 
	// LCSuff[i][j] contains length of longest 
	// common suffix of X[0..i-1] and Y[0..j-1]. 

	int LCSuff[m + 1][n + 1];
	int result = 0; // To store length of the 
					// longest common substring 

	/* Following steps build LCSuff[m+1][n+1] in
		bottom up fashion. */
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{

			// The first row and first column 
			// entries have no logical meaning, 
			// they are used only for simplicity 
			// of program 
			if (i == 0 || j == 0)
				LCSuff[i][j] = 0;

			else if (X[i - 1] == Y[j - 1])
			{
				LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
				result = max(result, LCSuff[i][j]);
			}
			else LCSuff[i][j] = 0;
		}
	}
	return result;
}


/* Driver program to test above function */
int main()
{
	char X[] = "OldSite:GeeksforGeeks.org";
	char Y[] = "NewSite:GeeksQuiz.com";

	int m = strlen(X);
	int n = strlen(Y);

	cout << "Length of Longest Common Substring is "
		<< LCSubStr(X, Y, m, n);
	return 0;
}

#endif