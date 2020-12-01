// possibility of minus input   -> Need to check again.. 


#include <iostream>
#include <vector>

using namespace std;

/*
 . Keeping a running sum of all the elements so far as we iterate through them
 . If the running sum is equal to k, then we can increment the answer by 1 because then we have found a valid subarray that starts from index 0
 . If there is a prefix sum for sum - k in the map, that means we can form sum = k
    - This is because the prefix sum for sum subtracted by the the prefix sum for sum - k is k(sum - (sum - k) = k).This means that we can take all of the elements up to sum and subtract it by all of the elements up to sum - k to get k.
 . Increase the value in the map for the current running sum
*/

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> mp;
		int sum = 0, ans = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			if (sum == k) ans++;
			if (mp[sum - k])
				ans += mp[sum - k];
			mp[sum]++;
		}
		return ans;
	}
};


class _Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int l = nums.size();

		int st = 0, ed = 0, sum = 0;
		int cnt = 0;
		
		if (l < 0) return cnt;
		if (l == 1) {
			if (k == nums[0]) return 1;
			else return 0;
		}

		// initial setup
		ed = -1;
		do {
			ed++;
			if (ed >= l) return cnt;
			sum += nums[ed];
		} while (sum < k);

		if (sum == k) cnt++;

		do {
			sum -= nums[st];
			st++;

			if (sum > k) continue;
			if (sum == k) {
				cnt++;
				continue;
			}

			do {
				ed++;
				if (ed >= l) return cnt;
				sum += nums[ed];
			} while (sum < k);
			if (sum == k) cnt++;
		} while (ed < l && st < l);

		return cnt;
	}
};


int main() {
	char c;
	Solution sol;
	//vector<int> n = { 1, 1, 1 };
	//vector<int> n = { 1, 2, 3 };
	//vector<int> n = { 1};
	vector<int> n = { -1, -1, 1 };

	cout << sol.subarraySum(n, 0);

	cin >> c;
}