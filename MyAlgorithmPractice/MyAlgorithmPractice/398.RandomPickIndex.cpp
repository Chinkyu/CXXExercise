#include <iostream>
#include <vector>
#include <unordered_map>
#include <ctime>

using namespace std;

class Solution {
public:
	unordered_map<int, list<int>> um;

	Solution(vector<int>& nums) {
		int l = nums.size();

		srand(time(NULL));

		for (int i = 0; i < l; ++i) {
			um[nums[i]].push_back(i);
		}


	}

	int pick(int target) {
		int sz = um[target].size();

		if (sz == 1) return um[target].front();

		int r = rand() % sz;
		auto it = um[target].begin();
		for (int j = 0; j < r; j++) it++;
		return *it;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

int main() {
	char c;

	vector<int> nums = {1, 2, 3, 3, 3};
	Solution* obj = new Solution(nums);

	cout << obj->pick(3) << endl;
	cout << obj->pick(3) << endl;
	cout << obj->pick(3) << endl;
	cout << obj->pick(3) << endl;
	cout << obj->pick(3) << endl;
	cout << obj->pick(2) << endl;

	cin >> c;
}