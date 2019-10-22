#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
	vector<int> &n;
	vector<int> ac;
	NumArray(vector<int>& nums): n(nums) {
		int l = nums.size();
		if (l <= 0) return;
		
		ac.resize(l);
		ac[0] = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			ac[i] = ac[i - 1] + nums[i];
		}
	}

	void update(int i, int val) {
		int delta = n[i] - val;
		n[i] = val;
		for (int j = i; j < n.size(); ++j) {
			ac[j] -= delta;
		}
	}

	int sumRange(int i, int j) {
		if (i == 0) {
			return ac[j];
		}
		else {
			return ac[j] - ac[i-1];
		}
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

int main(void) {
	char ch;
	vector<int> nums = { 1, 3, 5 };
	//vector<int> nums = { 3,-8 };

	NumArray* obj = new NumArray(nums);
	//obj->update(i, val);
	cout << obj->sumRange(0, 2);
	obj->update(1, 2);
	cout << obj->sumRange(0, 2);

	cin >> ch;
}