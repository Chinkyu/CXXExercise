#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	int next(vector<int>& nums, int i) {
		int n = nums.size();
		return (n + nums[i] + i) % n;
	}

	bool circularArrayLoop(vector<int>& nums) {
		int n = nums.size();
		// we can use slow and fast pointer to check whether there is loop or not
		for (int &num : nums)
			num %= n;
		for (int i = 0; i < n; i++) {
			int slow = i,
				fast = i;
			while (nums[slow] * nums[next(nums, fast)] > 0 && nums[slow] * nums[next(nums, next(nums, fast))] > 0) {
				slow = next(nums, slow);
				fast = next(nums, next(nums, fast));
				if (slow == fast) {
					if (slow == next(nums, slow)) // single length
						return false;
					return true;
				}
			}
			/// DONOT TRAVERSE WHERE THERE IS NO PATH TO GET LOOP.
			int j = i;
			int val = nums[i];
			while (nums[j] * val > 0) {
				int nexx = next(nums, j);
				nums[j] = 0;
				j = nexx;
			}
		}

		return false;
	}
};


class _Solution {
public:
	int max = 0;
	bool isrunStart(int s, int e, int ck, bool isPositive) {

		//::XXXX : Need check negative inclusion

		if (isPositive) {

			if (s < e) {
				if (s < ck && ck <= e) return true;
			}
			else if (s > e) {
				if ((0 <= ck && ck <= e) ||
					(s < ck && ck <= max - 1)) {
					return true;
				}
			}
			else {
				if (s == ck) true;
			}
		}
		else {
			if (e < s) {
				if (e <= ck && ck < s) return true;
			}
			else if (e > s) {
				if ((0 <= ck && ck < s) ||
					(e <= ck && ck <= max - 1)) {
					return true;
				}
			}
			else {
				if (s == ck) true;
			}
		}
		return false;
	}
	bool circularArrayLoop(vector<int>& nums) {
		max = nums.size();
		
		bool isPositive = true;
		for (int i = 0; i < max; ++i) {
			isPositive = false;
			if (nums[i] > 0) isPositive = true;

			int start = i;
			int prev, next;

			prev = next = i;

			int idx = next;
			do {
				prev = next;
				next = prev + nums[prev];

				if (next >= max) next %= max;
				if (next < 0) next = max + next;

				if (isPositive && nums[next] < 0) break;
				if (!isPositive && nums[next] > 0) break;

				if (next == prev) break;
				if (next == start) return true;

			} while (isrunStart(prev, next, start, isPositive) == false);

		}
		return false;
	}
};

int main() {
	char c;
	Solution sol;
	vector<int> v = { 1, 2, 3, 4, 5 }; // { -1, 2 };// { 2, -1, 1, 2, 2 };

	cout << sol.circularArrayLoop(v);
	cin >> c;
}