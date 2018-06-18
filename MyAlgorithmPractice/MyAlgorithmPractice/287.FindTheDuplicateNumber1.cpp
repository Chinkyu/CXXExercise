#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int findDuplicate1(vector<int>& nums) {
		int xorN1, xorN;

		xorN1 = 0;
		xorN = 0;
		for (int i = 0; i < nums.size(); i++) {
			xorN1 ^= nums[i];
		}

		for (int i = 1; i < nums.size(); i++) {
			xorN ^= i;
		}

		return xorN1 ^ xorN;

	}
	int findDuplicate(vector<int>& nums) {

		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[i] == nums[j]) return nums[i];
			}
		}

		return -1;
	}
};




int main() {
	char c;
	Solution s;
	vector<int> n = { 1, 3, 4, 2, 2 };

	cout << s.findDuplicate(n);
	cin >> c;
}