#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

class Solution {
public:
	bool isFind = false;
	bool traverse(int sum, int target, int idx, vector<int>& nums) {
		cout << idx << endl;
		if (isFind == true) return true;
		if (idx >= nums.size()-1) return false;
		if (sum == target) {
			isFind = true;
			return true;
		}
		else if (sum > target) {
			return false;
		}

		bool wo = traverse(sum, target, idx + 1, nums);
		bool w = traverse(sum + nums[idx], target, idx + 1, nums);
		return wo | w;
	}

	bool canPartition(vector<int>& nums) {

		if (nums.size() <= 1) return false;
		int sum = 0;

		for (auto it : nums) sum += it;

		if (sum % 2 != 0) return false;

		isFind = false;
		traverse(0, sum / 2, 0, nums);

		if (isFind == true) return true;
		return false;
	}

};

class __Solution {  // magical solution 
public:
	bool canPartition(vector<int>& nums) {
		const int MAX_NUM = 100;
		const int MAX_ARRAY_SIZE = 200;
		bitset<MAX_NUM * MAX_ARRAY_SIZE / 2 + 1> bits(1);
		int sum = 0;
		for (auto n : nums) {
			sum += n;
			bits |= bits << n;
		}
		return !(sum % 2) && bits[sum / 2];
	}
};

class ___Solution {
public:
	bool isFind = false;
	bool traverse(int sum, int target, int idx, vector<int>& nums) {
		if (isFind == true) return true;
		if (idx >= nums.size()) return false;
		if (sum == target) {
			isFind = true;
			return true;
		}
		else if (sum > target) {
			return false;
		}

		bool wo = traverse(sum, target, idx + 1, nums);
		bool w = traverse(sum + nums[idx], target, idx + 1, nums);
		return wo | w;
	}

	bool canPartition(vector<int>& nums) {

		if (nums.size() <= 1) return false;
		int sum = 0;

		for (auto it : nums) sum += it;

		if (sum % 2 != 0) return false;

		isFind = false;
		traverse(0, sum / 2, 0, nums);

		if (isFind == true) return true;
		return false;
	}

};


class _Solution {
public:
	bool _canPartition(vector<int>& nums) {

		if (nums.size() <= 1) return false;

		sort(nums.begin(), nums.end());
		int s = 0, e = nums.size() - 1;
		int sm = nums[s], em = nums[e];
		while(s + 1 < e) {
			if (sm < em) {
				sm += nums[++s];
			}
			else{
				em += nums[--e];
				
			}
		};

		if (sm == em) return true;
		else return false;
	}

	bool canPartition(vector<int>& nums) {

		if (nums.size() <= 1) return false;

		sort(nums.begin(), nums.end());
		int e = nums.size() - 1;
		int sm = nums[e--];
		int em = nums[e--];
		while (e >= 0) {
			if (sm < em) {
				sm += nums[e--];
			}
			else {
				em += nums[e--];

			}
		};

		if (sm == em) return true;
		else return false;
	}
};

int main() {
	char c;
	Solution sol;
vector<int> v = { 3, 2, 1,4,5,6,7 , 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19}; // { 1, 1 }; // { 1, 5, 11, 5 };
//	vector<int> v = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};

	cout << sol.canPartition(v);

	cin >> c;
}