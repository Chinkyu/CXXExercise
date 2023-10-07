// 답이 풀리는게.. 이해가 안감..   Frequency domain에서 품... ㅠㅠ
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

//  요거는 이해 안감... 
class Solution {
public:
	long long countBadPairs(vector<int>& arr) {
		unordered_map<int, int> freq;
		long long ans = 0, n = arr.size();
		for (int i = 0; i < n; i++)
		{
			arr[i] = i - arr[i];
			freq[arr[i]]++;
		}
		for (int i = 0; i < n; i++)
		{
			freq[arr[i]]--;
			ans += (n - i - 1 - freq[arr[i]]);
		}
		return ans;
	}
};


class Solution {
public:
	long long countBadPairs(vector<int>& nums) {
		unordered_map<long long, long long>m;
		long long n = nums.size();
		long long total = n * (n - 1) / 2;
		for (int i = 0; i < nums.size(); i++)
		{
			m[nums[i] - i]++;
		}
		unsigned long long count = 0;
		for (auto it : m)
		{
			if (it.second > 1)
			{
				count += ((it.second * (it.second - 1)) / 2);
			}
		}
		return total - count;

	}
};

class _Solution {
public:

	// timeout
	long long countBadPairs(vector<int>& nums) {
		int l = nums.size();
		vector<int> inc(l, 0);

		for (int i = 1; i < l; ++i) {
			inc[i] = nums[i] - nums[i - 1];
		}

		long long count = 0;
		for (int i = 1; i < l; ++i) {
			//vector<int> acc(l, 0);
			long long accu = 0;
			for (int j = i, k = 1; j < l; ++j, ++k) {
				accu += inc[j];
				if (accu != k) {
					count++;
					cout << i << " " << j << endl;
				}
			}
		}
		return count;
	}

	long long _countBadPairs(vector<int>& nums) {
		int l = nums.size();
		vector<int> inc(l, 0);

		for (int i = 1; i < l; ++i) {
			inc[i] = nums[i] - nums[i - 1];
		}

		long long count = 0;
		long long accu = 0;
		for (int i = 1; i < l; ++i) {
			accu += inc[i];
			if (accu != i) {
				count += i;
			}
		}
		return count;
	}

};



int main() {
	char c;

	Solution sol;

	vector<int> nums = { 4, 1, 3, 3 };

	cout << sol.countBadPairs(nums);

	cin >> c;

}