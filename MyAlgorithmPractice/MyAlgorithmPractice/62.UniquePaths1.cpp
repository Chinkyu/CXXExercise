#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> mat(m, vector<int>(n, 0));

		for (int i = 0; i < m; ++i) mat[i][0] = 1;
		for (int i = 0; i < n; ++i) mat[0][i] = 1;

		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				mat[i][j] = mat[i - 1][j] + mat[i][j - 1];
			}
		}

		return  mat[m-1][n-1];
	}
};


// Wrong Solution ..... C(l+1, s)  인지 알고 풀었음 -> 틀림
class Solution2 {
public:

	// reference from GeeksforGeeks
	// https://www.geeksforgeeks.org/binomial-coefficient-dp-9/
	int binomialCoeff(int n, int k) {

		// C(n, 0) == C(n, n) = 1
		if (k == 0 || k == n) return 1;

		// C(n,k) = C(n-1, k-1) + C(n-1, k)
		return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
	}

	int uniquePaths(int m, int n) {
		int l, s;

		if (m > n) {
			l = m-1; s = n-1;
		}
		else {
			l = n-1; s = m-1;
		}

		if (s == 0) return l;

		// (l+1)Cs

		// OverFlow solution 

		//long long a, b, c;
		//a = b = c = 1;
		//long long p = 1;
		//for (int i = 1; i <= l + 1; i++) {
		//	p *= i;
		//	if (i == l + 1) a = p;
		//	if (i == s) b = p;
		//	if (i == l + 1 - s) c = p;
		//}
		// 	return a / (b*c);

		// (l+1)Cs
		return binomialCoeff(l + 1, s);


	}
};

int main() {
	Solution sol;
	char c;

	cout << sol.uniquePaths(7, 3);

	cin >> c;
}