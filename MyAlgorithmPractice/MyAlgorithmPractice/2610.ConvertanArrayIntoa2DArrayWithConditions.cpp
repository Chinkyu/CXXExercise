// ¾î·ÆÁö ¾Ê°Ô...
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
	vector<vector<int>> findMatrix(vector<int>& nums) {
		unordered_map<int, int> c;
		vector<vector<int>> ans;
		for (auto it : nums) c[it]++;

		bool isAllZero = true;
		do {
			isAllZero = true;
			vector<int> r;
			for (auto it : c) {
				if (it.second != 0) {
					r.push_back(it.first);
					c[it.first]--;
					isAllZero = false;
				}
			}
			if(isAllZero == false) ans.push_back(r);

		} while (isAllZero == false);

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> nums ={4, 10, 5, 5, 3, 4, 4, 5, 3, 3}; // { 1, 3, 4, 1, 2, 3, 1 };
	vector<vector<int>> ans = sol.findMatrix(nums);

	for (auto it : ans) {
		for (auto jt : it) {
			cout << jt << " ";
		}
		cout << endl;
	}

	cin >> c;
}
