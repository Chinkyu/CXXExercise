#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> shuffle(vector<int>& nums, int n) {
		vector<int> ans(n*2, 0);

		int j = 0;
		for (int i = 0; i < n; i++) {
			ans[j++] = nums[i];
			ans[j++] = nums[i + n];
		}
		return ans;
	}
};

int main() {
	char c;
	Solution s;

	vector<int> nums = { 2,5,1,3,4,7 };

	vector<int> ans = s.shuffle(nums, 3);
	for (auto it : ans) {
		cout << it << " ";
	}
	cout << endl;

	cin >> c;
}