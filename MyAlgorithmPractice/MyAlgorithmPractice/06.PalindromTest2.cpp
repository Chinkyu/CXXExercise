// Need to add Memoization 

#include <iostream>
#include <string>

using namespace std;

int max(int x, int y) { return (x > y) ? x : y; }

class Solution {
public:
	int maxLength;
	int maxs;
	int maxe;

	Solution():maxLength(0), maxs(0), maxe(0) {};
public:
	int internalLP(string &seq, int i, int j) {
		if (i == j) return 1;
		if (seq[i] == seq[j] && i + 1 == j) return 2;

		if (seq[i] == seq[j]) {
			int r = internalLP(seq, i + 1, j - 1) + 2;
			if (maxLength < r) {
				maxLength = r;
				maxs = i;
				maxe = j;
			}
			return r;
		}
		else {
			int r1 = internalLP(seq, i, j - 1);
			int r2 = internalLP(seq, i + 1, j);
			int r3 = max(r1, r2);
			if (r1 == r3 && maxLength < r3) {
				maxLength = r1;
				maxs = i;
				maxe = j - 1;
			}
			else {
				maxLength = r2;
				maxs = i+1;
				maxe = j;
			}
			return r3;
		}
	}

	string longestPalindrome(string s) {
		string r;
		cout << internalLP(s, 0, s.length() - 1) << " " << maxs << " " << maxe;
		r = s.substr(maxs, maxe - maxs-1);
		return r;
	}
};

int main() {
	int i;
	Solution sol;
	string s("BBABCBCAB"); //  "GEEKSFORGEEKS");
	cout << "the length of the LPS is " << sol.longestPalindrome( s);

	cin >> i;

}