#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
		int size = nums.size();
		vector<string> ans;
		
		if (size <= 0) return ans;
		int st = 0, ed = 0;
		int cur = nums[st];

		st = ed = 0;
		for(int i = 1; i <= size; ++i) {
			if (i == size || cur + 1 != nums[i]) {
				if (st + 1 == i) { // only one number
					ans.push_back(to_string(nums[st]));
					st = i;
				}
				else {
					string s = to_string(nums[st]);
					s.append("->");
					s.append(to_string(nums[i - 1]));
					ans.push_back(s);
					st = i;
				}
			} 
			//else {
				if(i < size) cur = nums[i];
			//}
		}
		return ans;
	}
};

int main() {
	Solution sol;
	char c;
	vector<int> v = { 0, 1, 2, 4, 5, 7 };
	vector<string> ans = sol.summaryRanges(v);
	
	for (auto it : ans) {
		cout << it << endl;
	}
	cin >> c;
}
