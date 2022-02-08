#include <iostream>
#include <vector>

using namespace std;

#define BLOCK 1
#define EMPTY 2
#define TBD   3
#define FILL  4

class Solution {
public:
	int trap(vector<int>& height)
	{
		if (height.empty())
			return 0;
		int ans = 0;
		int size = height.size();
		vector<int> left_max(size), right_max(size);
		left_max[0] = height[0];
		for (int i = 1; i < size; i++) {
			left_max[i] = max(height[i], left_max[i - 1]);
		}
		right_max[size - 1] = height[size - 1];
		for (int i = size - 2; i >= 0; i--) {
			right_max[i] = max(height[i], right_max[i + 1]);
		}
		for (int i = 1; i < size - 1; i++) {
			ans += min(left_max[i], right_max[i]) - height[i];
		}
		return ans;
	}

	int _trap(vector<int>& height) {   // memory full error 
		int num = height.size();

		// find max 
		int max = -1;
		for (auto it: height) {
			if (it > max) max = it;
		}

		// make plate & setup block & TBD
		vector<vector<int>> plate(num, vector<int>(max, 0));

		for (int i = 0; i < num; ++i) {
			for (int j = 0; j < max; ++j) {
				if (j < height[i]) {
					plate[i][j] = BLOCK;
				}
				else {
					plate[i][j] = TBD;
				}

			}
		}

		for (int j = 0; j < max; ++j) {
			// Checking from left 
			for (int i = 0; i < num; ++i) {
				if (plate[i][j] == BLOCK) break;
				if (plate[i][j] == TBD) {
					plate[i][j] = EMPTY;
				}
			}
			// checking from right
			for (int i = num - 1; i >= 0; --i) {
				if (plate[i][j] == BLOCK) break;
				if (plate[i][j] == TBD) {
					plate[i][j] = EMPTY;
				}
			}
		}

		// Search TBD block, find it is enclosed 
		for (int i = 0; i < num; ++i) {
			for (int j = 0; j < max; ++j) {
				if (plate[i][j] == TBD) {
					// toward left
					bool leftFound = false;
					for (int k = i; k >= 0; --k) {
						if (plate[k][j] == BLOCK) {
							leftFound = true;
							break;
						}
					}

					// toward right
					bool rightFound = false;
					for (int k = i; k < num; ++k) {
						if (plate[k][j] == BLOCK) {
							rightFound = true;
							break;
						}
					}

					if ((true == leftFound) && (true == rightFound)) {
						plate[i][j] = FILL;
					}
					else {
						plate[i][j] = EMPTY;
					}

				}
			}

		}

		// count FILL
		int count = 0;
		for (auto it : plate) {
			for (auto jt : it) {
				if (jt == FILL) ++count;
			}
		}

		return count;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	cout << sol.trap(height);

	cout << "test" << endl;

	cin >> c;
}