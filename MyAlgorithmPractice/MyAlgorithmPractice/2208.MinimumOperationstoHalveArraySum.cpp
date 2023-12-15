//  easy with heap
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <iomanip>

using namespace std;

class Solution {
public:
	int halveArray(vector<int>& nums) {
		vector<double> h;
		double hsum = 0;

		for (auto &it : nums) {
			h.push_back(it);
			hsum += it;
		}

		double csum = hsum;
		hsum = hsum / 2;
		make_heap(h.begin(), h.end());

		int ans = 0;
		while (csum > hsum) {
			double c = h.front();
			pop_heap(h.begin(), h.end());
			h.pop_back();

			c = c / 2;
			csum -= c;

			h.push_back(c);
			push_heap(h.begin(), h.end());

			ans++;
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;


	vector<int> nums = { 5, 19, 8, 1 };
	cout << sol.halveArray(nums);

	cin >> c;

}