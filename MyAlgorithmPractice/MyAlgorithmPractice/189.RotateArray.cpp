// 다른 여러가지 방법이 있다는데.....    !!  해봐야 하는데.... 

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
	void rotate(vector<int>& nums, int k) {

		if (nums.size() <= 1) return;

		k = k % nums.size();

		vector<int> tv(nums.size(), 0);
		for (int i = 0, j = k; i < nums.size() - k; ++i, j++) {
			tv[j] = nums[i];
		}

		for (int i = 0; i < k; ++i) {
			tv[i] = nums[nums.size() - k + i];
		}

		nums = tv;
	}
};

int main() {
	char c;

	Allocator alloc(10);

	alloc.allocate(1, 1);
	alloc.allocate(1, 2);
	alloc.allocate(1, 3);
	alloc.free(2);
	alloc.allocate(3, 4);
	alloc.allocate(1, 1);
	alloc.allocate(1, 1);
	alloc.free(1);
	alloc.allocate(10, 2);
	alloc.free(7);

	//	cout << sol.garbageCollection(garbage, travel);

	cin >> c;
}