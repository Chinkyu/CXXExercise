#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int n = nums.size();

		if (n <= 1) return;
		int s = 0, e = n - 1;

		while (e >= 0 && nums[e] == 2) e--;
		if (e < 0) return;

		for (int i = 0; i <= e; ++i) {
			if (nums[i] == 0) {
				nums[s++] = 0;
			}
			else if (nums[i] == 2) {
				while (e >= 0 && nums[e] == 2) e--;
				if (e < i) {
					break;
				}
				if (nums[e] == 0) { // swap
					nums[i] = 1;
					nums[s++] = 0;
					nums[e--] = 2;
				}
				else { // nums[e] == 1
					nums[i] = 1;
					nums[e--] = 2;
				}
			}
		}

		for (int i = s; i <= e; ++i) nums[i] = 1;
	}
};


int main() {
	Solution sol;
	char c;

	//vector<int> v = { 2, 0, 2, 1, 1, 0 };
	vector<int> v = { 1,1,1,0,0,0,2,0,1,1,1,1,1,0,1,0,0,2,1,1,2,2,2,0,0,1,1,2,2,2,0,1,0,0,0,1,0};
	//vector<int> v = { 0, 2, 1, 2, 0, 2, 0, 1 };

	sol.sortColors(v);

	for (auto it: v) {
		cout << it << " ";
	}
	cout << endl;

	cin >> c;
}