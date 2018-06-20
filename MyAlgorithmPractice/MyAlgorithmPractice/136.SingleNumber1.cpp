#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;

		for (auto e : nums) {
			res ^= e;
		}
		return res;
	}
};



int main() {
	char c;
	vector<int> n = { 4, 1, 2, 1, 2 };
	Solution sol;

	cout << sol.singleNumber(n) << endl;


	cin >> c;
}