#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int end = nums.size() - 1;
		int mi, si = 0, ei = end;

		while (si + 1 < ei) {
			mi = (si + ei) / 2;
			if (mi == 0 && nums[0] > nums[1]) return 0;
			if (mi == end && nums[end - 1] < nums[end]) return end;

			if (nums[mi - 1] > nums[mi]) ei = mi;  // look left
			else si = mi; // look right
		}

		return (nums[si] < nums[ei]) ? ei : si;
	}
};

int main() {
	Solution sol;
	char c;

	//vector<int> v = {4, 5, 7, 0, 1, 2};
	vector<int> v = { 1, 2, 3, 1 };

	cout << sol.findPeakElement(v);

	cin >> c;
}
