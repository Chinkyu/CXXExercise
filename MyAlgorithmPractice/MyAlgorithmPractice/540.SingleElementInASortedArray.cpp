#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int ans= 0;
		for (auto it : nums) {
			ans ^= it;
		}
		return ans;
	}
};

int main() {
	char c;
	Solution sol;
	vector<int> n = { 1, 1, 2, 3, 3, 4, 4, 8, 8 };

	cout << sol.singleNonDuplicate(n);
	cin >> c;
}