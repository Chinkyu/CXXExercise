//  easy
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

class Solution {
public:
	int reverse(int n1) {

		string str = to_string(n1);
		int n = str.size();

		for (int i = 0; i < n / 2; ++i) {
			swap(str[i], str[n - i - 1]);
		}

		return stoi(str);
	}
	int countDistinctIntegers(vector<int>& nums) {

		vector<int> tnums = nums;
		for (auto it : tnums) {
			nums.push_back(reverse(it));
		}

		set<int> s;
		for (auto it : nums) s.insert(it);

		return s.size();
	}
};

int main() {
	char c;

	Solution sol;
	vector<int> nums = { 1, 13, 10, 12, 31 };

	cout << sol.countDistinctIntegers(nums);

	cin >> c;
}