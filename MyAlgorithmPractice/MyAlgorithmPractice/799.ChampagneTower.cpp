//  답 봤음...   답은.... 아주 쉽게 품... 
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

using namespace std;

class Solution {
public:
	double champagneTower(int poured, int query_row, int query_glass) {

		vector<vector<double>> m = vector<vector<double>>(101, vector<double>(101, 0));

		m[0][0] = poured;

		for (int i = 0; i < 100; ++i) {
			for (int j = 0; j <= i; ++j) {
				if (m[i][j] > 1) {
					m[i + 1][j] += (m[i][j] - 1) / 2.0;
					m[i + 1][j + 1] += (m[i][j] - 1) / 2.0;
					m[i][j] = 1;
				}
			}
		}

		return m[query_row][query_glass];

	}
};


int main() {
	char c;

	Solution sol;

	cout << sol.champagneTower(100000009, 33, 17);

	cin >> c;
}