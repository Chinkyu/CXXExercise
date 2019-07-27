#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int st = 0, ed = 0, sum = 0;
		int n = nums.size();
		int min = n;
		bool isNeverHit = true;

		if (n <= 0) return 0;

		sum = nums[0];
		for(int st = 0; st < n; ++st) {

			while(ed+1 < n && sum < s) {
				sum += nums[ed+1];
				ed++;
			}
			if (ed - st + 1 <= min && sum >= s) {
				min = ed - st + 1;
				isNeverHit = false;
			}
			sum -= nums[st];
		}

		if (isNeverHit == true) return 0;
		return min;
    }
};


int main() {
	Solution sol;
	char c;
//	vector<int> v = { 2, 3, 1, 2, 4, 3 };
	vector<int> v = { 1, 2, 3, 4, 5 };

	cout << sol.minSubArrayLen(15, v);

	cin >> c;
}
