
/*
bool increasingTriplet(vector<int>& nums) {
	int c1 = INT_MAX, c2 = INT_MAX;
	for (int x : nums) {
		if (x <= c1) {
			c1 = x;           // c1 is min seen so far (it's a candidate for 1st element)
		} else if (x <= c2) { // here when x > c1, i.e. x might be either c2 or c3
			c2 = x;           // x is better than the current c2, store it
		} else {              // here when we have/had c1 < c2 already and x > c2
			return true;      // the increasing subsequence of 3 elements exists
		}
	}
	return false;
}

 이 두개의 답은 정확 한 답이 아님... !!!!!! 
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool _increasingTriplet(vector<int>& nums) {
		int c1 = INT_MAX, c2 = INT_MAX;
		for (int it : nums) {
			if (it <= c1) {
				c1 = it;
			}
			else if (it <= c2) {
				c2 = it;
			}
			else {
				return true;
			}
		}
		return false;
	}
	bool increasingTriplet(const vector<int>& nums) {
		int min = INT_MAX;
		int mid = INT_MAX;
		for (auto n : nums)
		{
			if (n < min)
			{
				min = n;
			}
			else if (n > min)
			{
				if (mid < n)
					return true;
				mid = n;
			}
		}
		return false;
	}
};

int main() {
	char c;
	vector<int> nums = 
	//{ 1, 2, 3, 4, 5 };
	{ 2, 10, 1, 12, 5 };
	Solution sol;

	cout << sol.increasingTriplet(nums);

	cin >> c;

}