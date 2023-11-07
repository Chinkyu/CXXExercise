//  easy with set 
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
	int partitionArray(vector<int>& nums, int k) {
		set<int> s;
		for (auto it : nums) s.insert(it);

		int ans = 0;
		while (!s.empty()) {
			int st = *(s.begin());
			s.erase(st);
			ans++;

			while (!s.empty()) {
				int nt = *(s.begin());
				if (k < nt - st) break;
				s.erase(nt);
			}
		}
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> nums = { 3,6,1,2,5 };

	cout << sol.partitionArray(nums, 2);

	cin >> c;

}