// 답 봤는데.. 이렇게 하면 답이 된다는게  신기하다.. !!!!!!! 
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
	int maximizeGreatness(vector<int>& nums) {
		int i = 0, sz = nums.size();
		sort(begin(nums), end(nums));
		for (int j = 0; j < sz; i += (j++) < sz)
			while (j < sz && nums[j] <= nums[i])
				++j;
		return i;
	}

	int _maximizeGreatness(vector<int>& nums) {
		
		if (nums.size() <= 1) return 0;
		
		sort(nums.begin(), nums.end());

		int first_size = 1;
		int first_num = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] == first_num) {
				first_size++;
			}
			else {
				break;
			}
		}

		set<int> s;
		for (int i = first_size; i < nums.size(); ++i) s.insert(nums[i]);


		return s.size();
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> grid = { 42,8,75,28,35,21,13,21 };

	cout << sol.maximizeGreatness(grid);


	//	cout << sol.countHighestScoreNodes(parents) << endl;
	//	cout << "test : " << ans << endl;

	cin >> c;
}