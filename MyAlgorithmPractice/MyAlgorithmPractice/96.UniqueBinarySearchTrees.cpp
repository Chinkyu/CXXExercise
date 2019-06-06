// from Lee code
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
	std::map<int, int> *ht;

	Solution(){
		ht = new map<int, int>;
	}

	int generateTreesInRange(int low, int high, map<int, int> &ht) const {
		if (low == high) {
			ht[1] = 1;
			return 1;
		}
		else if (high < low) {
			return 0;
		}

		int cnt = 0;
		int left_combos, right_combos;
		for (int root_val = low; root_val <= high; ++root_val) {

			if (ht.find(root_val - 1 - low) != ht.end()) {
				left_combos = ht[root_val - 1 - low];
			}
			else {
				left_combos = generateTreesInRange(low, root_val - 1, ht);
				ht[root_val - 1 - low] = left_combos;
			}

			if (ht.find(high - root_val - 1) != ht.end()) {
				right_combos = ht[high - root_val - 1];
			}
			else {
				right_combos = generateTreesInRange(root_val + 1, high, ht);
				ht[high - root_val - 1] = right_combos;
			}
			

			//				for (auto l : left_combos) {
			//					for (auto r : right_combos) {
			//						auto t = new TreeNode(root_val);
			//						t->left = l;
			//						t->right = r;
			//						ret.push_back(t);
			//					}
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
		map<int, int> m;
		
		if (n < 1) {
			return 0;
		}
		return generateTreesInRange(1, n, m);
	}
};

int main() {
	Solution sol;
	char c;

	for (int i = 1; i < 20; ++i) {
		cout << i << " " << sol.numTrees(i) << endl;
	}

	cin >> c;
}



