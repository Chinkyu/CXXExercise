// accepted 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findLength(vector<int>& A, vector<int>& B) {
		int lenA = A.size();
		int lenB = B.size();
		int maxMatchCount = 0;
		int maxStartMatch = 0;

		bool isMatched = false;
		int matchCount = 0;
		int startMatch = 0;

		// check while shift right B vector 
		for (int i = 0; i < lenA; i++) {
			matchCount = 0;
			for (int j = 0; j < lenB && i + j < lenA; j++) {
				if (A[i + j] == B[j]) {
					if (isMatched == false) {
						isMatched = true;
						matchCount = 1;
						startMatch = i + j;
					}
					else {
						matchCount++;
					}

					if (matchCount > maxMatchCount) {
						maxMatchCount = matchCount;
						maxStartMatch = startMatch;
					}
				}
				else {
					isMatched = false;
				}
			}
		}

		isMatched = false;
		matchCount = 0;
		startMatch = 0;
		// check while shift right A vector 
		for (int i = 0; i < lenB; i++) {
			matchCount = 0;
			for (int j = 0; j < lenA && i + j < lenB; j++) {
				if (B[i + j] == A[j]) {
					if (isMatched == false) {
						isMatched = true;
						matchCount = 1;
						startMatch = i + j;
					}
					else {
						matchCount++;
					}

					if (matchCount > maxMatchCount) {
						maxMatchCount = matchCount;
						maxStartMatch = startMatch;
					}
				}
				else {
					isMatched = false;
				}
			}
		}

//		cout << maxMatchCount << " " << maxStartMatch << endl;

		return maxMatchCount;
	}
};

// dp solution... 
// dp[i][j] = dp[i+1][j+1] + 1;
class Solution2 {
public:
	int findLength(vector<int>& A, vector<int>& B) {
		int ans = 0;
		int lenA = A.size();
		int lenB = B.size();
		vector<vector<int>> dp(lenA+1, vector<int>(lenB+1));

		for (int i = lenA - 1; i >= 0; i--) {
			for (int j = lenB - 1; j >= 0; j--) {
				if (A[i] == B[i]) {
					dp[i][j] = dp[i + 1][j + 1] + 1;
					if (ans < dp[i][j]) ans = dp[i][j];
				}
			}
		}

		return ans;
	}
};

#define TEST_NUM 10

int main() {
	char ch;
	vector<int> a = { 5, 14, 53, 80,48 }; // { 1, 2, 3, 2, 1 };
	vector<int> b = { 50, 47, 3, 80, 83 }; // { 3, 2, 1, 4, 7 };
	Solution s;
	Solution2 s2;

	cout << s.findLength(a, b) << endl;
	cout << s2.findLength(a, b) << endl;

// Mass Testing.. 
	vector<int> c(TEST_NUM);
	vector<int> d(TEST_NUM);

	for (int j = 0; j < TEST_NUM; j++) {
		for (int i = 0; i < TEST_NUM; i++) {
			c[i] = rand() % TEST_NUM;
			d[i] = rand() % TEST_NUM;
		}

		cout << s.findLength(c, d) << " ";
		cout << s2.findLength(c, d) << endl;
		if (s.findLength(c, d) != s2.findLength(c, d)) {
			cout << "Result not mismatch. !!!!!" << endl;
		}	
	}
	cin >> ch;

}

