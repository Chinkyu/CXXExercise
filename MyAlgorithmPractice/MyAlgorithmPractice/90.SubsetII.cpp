#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
	int n = 0;
	int k = 0;

	void iteration(vector<int> & nums, set <vector<int>> & ans, vector<bool> &itr_tbl, vector<int> &itr_val, int itr_idx, int idx) {

		if (idx >= k) {
			ans.insert(itr_val);

			//for (auto it : itr_val) {
			//	cout << it << ",";
			//}
			//cout << endl;

			return;
		}

		for (int i = itr_idx; i < n; ++i) {
			if (itr_tbl[i] == false) {
				itr_val[idx] = nums[i];
				itr_tbl[i] = true;
				iteration(nums, ans, itr_tbl, itr_val, i + 1, idx + 1);
				itr_tbl[i] = false;
			}
		}
	}

	vector<vector<int>> subsetsWithDup (vector<int>& nums) {
		n = nums.size();
		
		sort(nums.begin(), nums.end());
		set<vector<int>> sAns;
		vector<vector<int>> ans;
		vector<bool> itr_tbl(n, false);

		for (int i = 0; i < n; ++i) {
			vector<int> itr_val(i+1, 0);
			itr_tbl.assign(n, false);
			k = i + 1;
			iteration(nums, sAns, itr_tbl, itr_val, 0, 0);
		}

		vector<int> t;
		ans.push_back(t);

		for (auto it : sAns) {
			ans.push_back(it);
		}

		return ans;
	}

	//  환상적인 아이디어임. 
	//  i = 0  경우  power set   [], n[1]  두개
	//  i = 1  경우  power set은 앞에것을 복사한뒤에 새로 복사한 것에 새 항목 n[2] 를 더함
	//            [], n[1], [] + n[2], n[1] + n[2]
	//  이런식으로 계속하면  n 개까지 가서 간단하게 답을 구할수 있음  
	//  From Lee Code 

	vector<vector<int>> _subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		const int n = nums.size();

		vector<vector<int>> res(1);
		int count = res.size();
		for (int i = 0; i < n; ++i)
		{
			if (i == 0 || nums[i] != nums[i - 1])
				count = res.size();
			int tmp = res.size();
			for (int j = tmp - count; j < tmp; ++j)
			{
				res.push_back(res[j]);
				res.back().push_back(nums[i]);
			}
		}
		return res;
	}

};

int main() {
	Solution sol;
	//vector<int> nums = { 1, 2, 2 };
	vector<int> nums = { 1, 2, 3};
	char c;

	vector<vector<int>> ans = sol.subsetsWithDup(nums);

	for (auto it : ans) {
		for (auto jt : it) {
			cout << jt << ",";
		}
		cout << endl;
	}

	cin >> c;
}