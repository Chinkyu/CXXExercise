//  Easy...
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

class LUPrefix {
public:
	int last_idx = 0;
	int vn = 0;
	vector<int> v;
	LUPrefix(int n) {
		vn = n;
		last_idx = 0;
		v = vector<int>(n + 1, 0);
	}

	void upload(int video) {
		v[video] = 1;

		while (last_idx + 1 <= vn && v[last_idx + 1] == 1) last_idx++;
	}

	int longest() {
		return last_idx;
	}
};

int main() {
	char c;

	Solution sol;
	vector<vector<int>> grid = { {6, 2, 1, 3},{4, 2, 1, 5},{9, 2, 8, 7},{4, 1, 2, 9} };

	cout << sol.maxSum(grid);

	cin >> c;
}