// accepted...  string 으로 그냥 map 을 해도 되는것임... 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	string findDifferentBinaryString(vector<string>& nums) {
		unordered_map<int, bool> m;
		int len = nums[0].size();

		// convert binary string to int 
		for (auto it : nums) {
			// from 0idx and 2 radix
			m[stoi(it, 0, 2)] = true;
		}

		for (int i = 0; i <= (pow(2,len) - 1); ++i) {
			if (m.find(i) == m.end()) {
				string ans;
				for (int j = len - 1; j >= 0; j--) ans.push_back((i & (0x01 << j)) != 0 ? '1' : '0');
				//return bitset<len>(i).to_string();
				return ans;
			}
		}

		return "";
	}
};

int main() {
	char c;

	Solution sol;
	//vector<string> nums = { "111", "011", "001" };
	vector<string> nums = { "0" };


	cout << sol.findDifferentBinaryString(nums) << endl;
	//	cout << "test : " << ans << endl;

	cin >> c;
}