//	pivot 이 여러개 있을경우 감안 필요 
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
	vector<int> pivotArray(vector<int>& nums, int pivot) {
		vector<int> pre, post;
		int pivotNum = 0;

		for (auto it : nums) {
			if (it < pivot) {
				pre.push_back(it);
			}
			else if (it == pivot) {
				pivotNum++;
			}
			else {
				post.push_back(it);
			}
		}

		for (int i = 0; i < pivotNum; ++i) {
			pre.push_back(pivot);
		}
		for (auto it : post) {
			pre.push_back(it);
		}

		return pre;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> nums = { 9,12,5,10,14,3,10 };

	vector<int> ans = sol.pivotArray(nums, 10);

	for (auto it : ans) {
		cout << it << " ";
	}

	cin >> c;
}
