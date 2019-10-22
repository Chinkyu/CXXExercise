#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> ans;
	vector<int> temp;
	bool iteration(int k, int n, int st, int sum) {
		int size = temp.size();
		if (size == k) {
			if (sum == n) {
				return true;
			}
			else {
				return false;
			}

		}
		else if (size > k) {
			return false;
		}

		for (int i = st; i <= 9; ++i) {
			temp.push_back(i);
			if (iteration(k, n, i + 1, sum + i)) {
				ans.push_back(temp);
			}
			temp.pop_back();
		}
		return false;
	}


	vector<vector<int>> combinationSum3(int k, int n) {
		ans.clear();
		temp.clear();

		iteration(k, n, 1, 0);
		return ans;
	}
};

int main() {
	Solution sol;
	char c;

	vector<vector<int>> r = sol.combinationSum3(3, 9);

	for (auto it : r) {
		for (auto jt : it) {
			cout << jt << " ";
		}
		cout << endl;
	}
	cin >> c;
}