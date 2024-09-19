// 답봤는데 : stack 가지고 푸는거 이해하기 힘든데....

/*
Keep a mono incrasing stackas result.
If current element a is smaller then the last element in the stack,
we can replace it to get a smaller sequence.

Before we do this,
we need to check if we still have enough elements after.
After we pop the last element from stack,
we have stack.size() - 1 in the stack,
there are A.size() - i can still be pushed.
if stack.size() - 1 + A.size() - i >= k, we can pop the stack.

Then, is the stack not full with k element,
we push A[i] into the stack.

Finally we return stack as the result directly.
*/



#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>
#include <set>
#include <list>
#include <regex>
#include <memory>

using namespace std;

class Solution {
public:
	vector<int> mostCompetitive(vector<int>& A, int k) {
		vector<int> stack;
		for (int i = 0; i < A.size(); ++i) {
			while (!stack.empty() && stack.back() > A[i] && stack.size() - 1 + A.size() - i >= k)
				stack.pop_back();
			if (stack.size() < k)
				stack.push_back(A[i]);
		}
		return stack;
	}
};


class _Solution {
public:
	vector<int> candidate;
	bool isCandidateExist = false;

	bool traverse(vector<int>& nums, int k, int idx, vector<int> &path, int ik) {

		if (ik == k - 1) {
			if (isCandidateExist == true && nums[idx] > candidate[ik]) return false;
			path[ik] = nums[idx];
			candidate = path;
			isCandidateExist = true;
			return true;
		}

		int base = nums[idx];
		for (int i = idx + 1; i < nums.size(); ++i) {
			if (base <= nums[i]) {
				if (isCandidateExist == true && nums[i] > candidate[ik]) continue;
				path[ik] = nums[i];
				traverse(nums, k, i, path, ik + 1);
			}
		}

		return false;
	}

	vector<int> mostCompetitive(vector<int>& nums, int k) {
		int l = nums.size();
		vector<int> path(k, 0);
		isCandidateExist = false;

		for (int i = 0; i < l - k; ++i) {
			path[0] = nums[i];
			traverse(nums, k, i+1, path, 1);
		}
		return candidate;
	}
};

int main() {
	char c;
	Solution sol;
	vector<int> nums = { 3, 5, 2, 6 };

	vector<int> ans = sol.mostCompetitive(nums, 2);
	for (auto it : ans) {
		cout << it << " ";
	}
	cin >> c;
}