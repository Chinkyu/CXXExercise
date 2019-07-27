#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
		int mi, si = 0, ei = nums.size()-1;
		
		while (si + 1 < ei) {
			mi = (si + ei) /2;
			if(nums[si] > nums[ei] && nums[mi] > nums[ei]) si = mi;
			else ei = mi;
		}

		return (nums[si] < nums[ei]) ? nums[si] : nums[ei];
    }
};

int main() {
	Solution sol;
	char c;

	//vector<int> v = {4, 5, 7, 0, 1, 2};
	vector<int> v = { 1, 2, 3 };

	cout << sol.findMin(v);

	cin >> c;
}
