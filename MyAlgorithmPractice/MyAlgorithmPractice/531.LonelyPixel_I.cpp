// ī��Ʈ ��̷� ���� Ǯ�� ����... 
// ó���� ���� �߸� �̾��ؼ�....  �ٸ��� Ǯ���ٰ� ��ħ. 
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
	int findLonelyPixel(vector<vector<char>>& picture) {
		int m = picture.size(), n = picture[0].size();
		vector<int> cMArr(m, 0), cNArr(n, 0);

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (picture[i][j] == 'B') {
					cMArr[i]++;
					cNArr[j]++;
				}
			}
		}

		int alone = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (picture[i][j] == 'B' && cMArr[i] == 1 && cNArr[j] == 1) {
					alone++;
				}
			}
		}
		return alone;

	}
};


//  �߸� ���� �ϰ� Ǫ��... 
class _Solution {
public:
	int findLonelyPixel(vector<vector<char>>& picture) {
		int m = picture.size(), n = picture[0].size();
		int alone = 0;

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				bool isAlone = true;
				if (picture[i][j] == 'B') {
					// m -1
					if (0 <= i - 1 && (picture[i - 1][j] == 'B' || picture[i - 1][j] == 'F')) {
						isAlone = false;
						picture[i - 1][j] = 'F';
					}
					// m + 1
					if (i + 1 < m && (picture[i + 1][j] == 'B' || picture[i + 1][j] == 'F')) {
						isAlone = false;
						picture[i + 1][j] = 'F';
					}
					// n - 1
					if (0 <= j - 1 && (picture[i][j-1] == 'B' || picture[i][j-1] == 'F')) {
						isAlone = false;
						picture[i][j-1] = 'F';
					}
					// n + 1
					if (j + 1 < n && (picture[i][j + 1] == 'B' || picture[i][j + 1] == 'F')) {
						isAlone = false;
						picture[i][j + 1] = 'F';
					}

					if (isAlone == true) alone++;
				}
			}
		}
		return alone;
	}
};

int main() {
	char c;

	Solution sol;

	vector<vector<char>> picture = { {'W', 'W', 'B'}, {'W', 'B', 'W'},{'B', 'W', 'W'} };
	cout << sol.findLonelyPixel(picture);

	cin >> c;
}