// 답봤음...기존까지 넣었던  R/C  를 빼주면 된다는데... 놀랍군... 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <cmath>

using namespace std;

class Solution {
public:
	long long matrixSumQueries(int n, vector<vector<int>>& q) {
		long long ans = 0;
		long long r = 0, c = 0;
		vector<int>row(n + 1), col(n + 1);
		// Here we are eliminating all the repeating queries and just keeping the most recent query
		// We are eliminating query by changing the type of the query
		for (int i = q.size() - 1; i >= 0; i--) {
			if (q[i][0] == 0) {
				if (row[q[i][1]] != 0) q[i][0] = 2;
				else row[q[i][1]] = 1;
			}
			else {
				if (col[q[i][1]] != 0) q[i][0] = 2;
				else col[q[i][1]] = 1;
			}
		}
		// Just adding the complete val*n and subtracting all the previous values that have been put into rows 
		// if the query is of column and vice versa
		for (auto& i : q) {
			if (i[0] == 0) {
				r += i[2];
				ans += i[2] * n;
				ans -= c;
			}
			else if (i[0] == 1) {
				c += i[2];
				ans += i[2] * n;
				ans -= r;
			}
		}
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	string s = "0010";// "5494"; // "52233";
	cout << sol.longestSemiRepetitiveSubstring(s);
	//cout << sol.longestString(3, 25, 48);

	cin >> c;
}
