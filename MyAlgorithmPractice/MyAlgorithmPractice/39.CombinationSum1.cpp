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

	void addVector(vector<int>& candi, int idx) {
		vector<int> v;
		v.clear();
		for (int i = 0; i <= idx; ++i) v.push_back(candi[i]);
		sort(v.begin(), v.end());
		s.insert(v);
	}

	void iteration(vector<int>& candi, int target, int idx, int sum) {

		for (auto a : candi) {
			//sum += a;
			if (sum + a == target) {
				if (cArray.size() <= idx) {
					cArray.push_back(a);
				}
				else {
					cArray[idx] = a;
				}
				addVector(cArray, idx);
				return;
			} else if (sum + a < target) {
				if (cArray.size() <= idx) {
					cArray.push_back(a);
				}
				else {
					cArray[idx] = a;
				}
				iteration(candi, target, idx + 1, sum + a);
			} if (sum + a> target) {
				return;
			} 

		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		comb_idx = 0;
		cArray_idx = 0;

		comb.clear();
		cArray.clear();
		s.clear();

		if (candidates.size() == 0) return comb;

		sort(candidates.begin(), candidates.end());
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
	vector<int> v = { 8, 7, 4, 3 };

	vector<vector<int>> ans = sol.combinationSum(v,11);

	for (auto v : ans) {
		for (auto i : v) {
			cout << i << " ";
		}
		cout << endl;
	}

	cin >> c;
}