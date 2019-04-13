#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

//---------------------------
//Use unordered_map[] like two sum solution.....
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		unordered_map<int, int> umap;

		for (int i = 0; i < nums.size(); ++i) {
			umap[nums[i]] = i;
		}

		int size = nums.size();
		//		set<set<int>> result;

		result.clear();
		for (int i = 0; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++) {
				if (umap.find(-(nums[i] + nums[j])) != umap.end()) {
					//result.insert(set<int>{ nums[i], nums[j], nums[k]});

					// if found is idx is existing one i or j -> continue
					if (umap[-(nums[i] + nums[j])] == i || umap[-(nums[i] + nums[j])] == j) continue;

					vector<int> v{ nums[i], nums[j], -(nums[i] + nums[j])};
					sort(v.begin(), v.end());
					result.push_back(v);
				}
			}
		}

//		sort(result.begin(), result.end());
//		auto it = unique(result.begin(), result.end());
//		result.erase(it, result.end());


		//		for (auto i : result) {
		//			v_result.push_back(vector<int> (i.begin(), i.end()));
		//		}
		return result;
	}
};


//------------------
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx
// BAD TIME OUT Solution
class Solution_brute_force {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {

//		vector<int> mynums = nums;
//		sort(mynums.begin(), mynums.end());
//		auto last = unique(mynums.begin(), mynums.end());
//		mynums.erase(last, mynums.end());

		int size = nums.size();
//		set<set<int>> result;
		vector<vector<int>> result;

		for (int i = 0; i < size - 2; i++) {
			for (int j = i + 1; j < size - 1; j++) {
				for (int k = j + 1; k < size; k++) {
					if (nums[i] + nums[j] + nums[k] == 0) {
						//result.insert(set<int>{ nums[i], nums[j], nums[k]});
						vector<int> v {nums[i], nums[j], nums[k]};
						sort(v.begin(), v.end());
						result.push_back(v);
					}
				}
			}
		}

		sort(result.begin(), result.end());
		auto it = unique(result.begin(), result.end());
		result.erase(it, result.end());


//		for (auto i : result) {
//			v_result.push_back(vector<int> (i.begin(), i.end()));
//		}
		return result;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> num{ -1, 0, 1, 2, -1, 4 };


	vector<vector<int>> res = sol.threeSum(num);

	for (auto it : res) {
		cout << it[0] << "," << it[1] << "," << it[2] << endl;
	}

	cin >> c;
}