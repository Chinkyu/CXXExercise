
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


// This is the way to find pair that sume of them is target
// from sorting numbers and traverse them with sum... 
// But the solution should make original array's index that is distroied when doing sorting
// should find other way. 
#if 0
#define TO_RIGHT 1
#define TO_LEFT 2

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ans(2, -1);
		unordered_map<int, int> umap;
		int v_size = nums.size();

		for (int i = 0; i < v_size; i++) {
			umap[nums[i]] = i;
		}


		sort(nums.begin(), nums.end());


		int st = -1, ed = v_size-1;
		int direction = 0;


		while (st != ed) {
			st++;
			if (nums[st] + nums[ed] == target) {
				ans[0] = umap.find(nums[st])->second;
				ans[1] = umap.find(nums[ed])->second;
				return ans;
			} else if (nums[st] + nums[ed] < target) {
				direction = TO_RIGHT;

				while (ed + 1 <= v_size - 1) {
					ed++;
					if (nums[st] + nums[ed] == target) {
						ans[0] = umap.find(nums[st])->second;
						ans[1] = umap.find(nums[ed])->second;
						return ans;
					}
					else if (nums[st] + nums[ed] > target) {
						break;   // not meet with st idx to right
					}
				}
			}
			else {
				direction = TO_LEFT;

				while (ed - 1 > st && ed - 1 >= 0) {
					ed--;
					if (nums[st] + nums[ed] == target) {
						ans[0] = umap.find(nums[st])->second;
						ans[1] = umap.find(nums[ed])->second;
						return ans;
					}
					else if (nums[st] + nums[ed] < target) {
						break;   // not meet with st idx to left
					}
				}

			}

		}
	}
};
#endif

// solution with unorderd_map and check itself after finding. 

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ans(2, -1);
		unordered_map<int, int> umap;

		for (int i = 0; i < nums.size(); i++) {
			umap[nums[i]] = i;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (umap.find(target - nums[i]) != umap.end()) { // exist
				if (umap[target - nums[i]] != i) { // if this is nor myself
					ans[0] = i;
					ans[1] = umap[target - nums[i]];
					return ans;
				}
			}
		}
		return ans;
	}
};

int main() {
	char c;
	vector<int> iv = { 3, 2, 4 }; //  { 2, 7, 11, 15 };
	Solution sol;

	vector<int> ans = sol.twoSum(iv, 6);
	for (auto i : ans) {
		cout << i << ',';
	}
	cout << endl;

	cout << "test" << endl;


	cin >> c;
}