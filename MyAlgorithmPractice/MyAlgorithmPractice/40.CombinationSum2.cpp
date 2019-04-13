#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	vector<vector<int>> comb;
	set<vector<int>> s;
	int comb_idx;
	vector<int> cArray;
	int cArray_idx;

	vector<bool> isSelected;

	void addVector(vector<int>& candi, int idx) {
		vector<int> v;
		v.clear();
		for (int i = 0; i <= idx; ++i) v.push_back(candi[i]);
		sort(v.begin(), v.end());
		s.insert(v);
	}

	void iteration(vector<int>& candi, int target, int idx, int sum) {

		for (int i = 0; i < candi.size(); ++i) {
			
			// skip already selected 
			if (isSelected[i] == true) continue;

			if (sum + candi[i] == target) {
				if (cArray.size() <= idx) {
					cArray.push_back(candi[i]);
				}
				else {
					cArray[idx] = candi[i];
				}
				//isSelected[i] = true;
				addVector(cArray, idx);
				return;
			}
			else if (sum + candi[i] < target) {
				if (cArray.size() <= idx) {
					cArray.push_back(candi[i]);
				}
				else {
					cArray[idx] = candi[i];
				}
				isSelected[i] = true;
				iteration(candi, target, idx + 1, sum + candi[i]);
				isSelected[i] = false;
			} if (sum + candi[i] > target) {
				return;
			}

		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		comb_idx = 0;
		cArray_idx = 0;

		comb.clear();
		cArray.clear();
		s.clear();
		isSelected.clear();

		if (candidates.size() == 0) return comb;

		sort(candidates.begin(), candidates.end());
		for (int i = 0; i < candidates.size(); ++i) isSelected.push_back(false);

		iteration(candidates, target, 0, 0);

		for (auto sIter : s) {
			comb.push_back(sIter);
		}
		return comb;
	}
};

int main() {
	Solution sol;
	char c;
	//vector<int> v = { 2, 3, 6, 7 };
	//vector<int> v = { 2, 3};
	//vector<int> v = { 8, 7, 4, 3 };
	//vector<int> v = { 10, 1, 2, 7, 6, 1, 5 };
	vector<int> v = { 2, 5, 2, 1, 2 };

	vector<vector<int>> ans = sol.combinationSum2(v, 5);

	for (auto v : ans) {
		for (auto i : v) {
			cout << i << " ";
		}
		cout << endl;
	}

	cin >> c;
}