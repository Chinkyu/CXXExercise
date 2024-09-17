// Its OK : Accumulator array using for XOR  - very slow but pass 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>
#include <set>
#include <list>
#include <regex>
#include <memory>

using namespace std;

// Need Other solution.. 
class _Solution {
public:
	int kthLargestValue(vector<vector<int>>& matrix, int k) {
		int l = matrix.size();
		int m = matrix[0].size();

		vector<vector<int>> lc = matrix, rc = matrix;
		
		for (int i = 0; i < l; ++i) {
			for (int j = 1; j < m; ++j) {
				lc[i][j] ^= lc[i][j - 1];
			}
		}

		for (int i = 0; i < m; ++i) {
			for (int j = 1; j < l; ++j) {
				rc[j][i] ^= rc[j-1][i];
			}
		}

		multiset<int> ms;
		for (int i = 0; i < l; ++i) {
			for (int j = 0; j < m; ++j) {
				ms.insert(lc[i][j] ^ rc[i][j]);
			}
		}

		return 1; // *(ms.rbegin() - (k - 1));

	}
};

class Solution {
public:
	int kthLargestValue(vector<vector<int>>& matrix, int k) {
		int l = matrix.size();
		int m = matrix[0].size();

		vector<vector<int>> c = matrix; //:: XXXX : 
		multiset<int> ms;

		ms.insert(c[0][0]);
		for (int i = 1; i < l; ++i) {
			c[i][0] = c[i - 1][0] ^ matrix[i][0];
			ms.insert(c[i][0]);
		}

		for (int i = 1; i < m; ++i) {
			c[0][i] = c[0][i - 1] ^ matrix[0][i];
			ms.insert(c[0][i]);
		}


		for (int i = 1; i < l; ++i) {
			for (int j = 1; j < m; ++j) {
				c[i][j] = c[i - 1][j] ^ c[i][j-1] ^ c[i - 1][j - 1] ^ matrix[i][j];
				ms.insert(c[i][j]);
			}
		}

		auto it = ms.rbegin();
		for (int i = 1; i < k; ++i) it = next(it);

		return *it;

	}
};

int main() {
	char c;
	Solution sol;
	//vector<vector<int>> matrix = { {5, 2},{1, 6} };
	vector<vector<int>> matrix = {{10, 9, 5}, {2, 0, 4}, {1, 0, 9}, {3, 4, 8}};

	cout << sol.kthLargestValue(matrix, 10);

	cin >> c;
}