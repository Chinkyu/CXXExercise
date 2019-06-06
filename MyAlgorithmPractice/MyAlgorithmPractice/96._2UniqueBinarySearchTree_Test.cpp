// from Lee code
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
private:
	
public:
//	Solution() {
//		memo = new map<int, int>;
//	}
	unordered_map<int, int> memo;

	int generateTreesInRange(int low, int high) {
		if (low == high) {
			memo[1] = 1;
			return 1;
		}
		else if (high < low) {
			return 0;
		}

		int cnt = 0;
		int left_combos, rigmemo_combos;
		for (int root_val = low; root_val <= high; ++root_val) {

			if (memo.find(root_val - 1 - low) != memo.end()) {
				left_combos = memo[root_val - 1 - low];
			}
			else {
				left_combos = generateTreesInRange(low, root_val - 1);
				memo[root_val - 1 - low] = left_combos;
			}

			if (memo.find(high - root_val - 1) != memo.end()) {
				rigmemo_combos = memo[high - root_val - 1];
			}
			else {
				rigmemo_combos = generateTreesInRange(root_val + 1, high);
				memo[high - root_val - 1] = right_combos;
			}


			//				for (auto l : left_combos) {
			//					for (auto r : right_combos) {
			//						auto t = new TreeNode(root_val);
			//						t->left = l;
			//						t->right = r;
			//						ret.push_back(t);
			//					}`
			//				}
			if (left_combos == 0 || right_combos == 0) {
				cnt += left_combos + right_combos;
			}
			else {
				cnt += left_combos * right_combos;
			}
		}

		return cnt;
	}

	int numTrees(int n) const {
		if (n < 1) {
			return 0;
		}
		return generateTreesInRange(1, n);
	}
};

int main() {
	Solution sol;
	char c;

	sol.test();

	cin >> c;
}



