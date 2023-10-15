// Index 랭킹 하고 실제 랭킹 하고 다름... 이거 때문에 엄청 해맸음... !!! 
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


// mis ranking concept : index is not ranking 
class Solution_v1 {
public:
	vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
		int l = nums.size();
		int dsize = nums[0].size();
		vector<vector<int>>  sarr (dsize, vector<int>(l, 0));


		// first soft array 
		vector<vector<int>> darray;
		for (int i = 0; i < l; ++i) {
			darray.push_back({ i, nums[i][dsize - 1] -'0' });
		}

		sort(darray.begin(), darray.end(), [](vector<int> &l, vector<int> &r) {
			if (l[1] == r[1]) return l[0] < r[0];
			return l[1] < r[1];
		});
		//sarr.push_back(darray[1]);
		for (int i = 0; i < l; ++i) sarr[0][i] = darray[i][0];

		for (int i = 1; i < dsize; ++i) {
			vector<vector<int>> darray;
			for (int j = 0; j < l; ++j) {
				darray.push_back({ j, nums[j][dsize - 1 - i] -'0'});
			}

			sort(darray.begin(), darray.end(), [&](vector<int> &l, vector<int> &r) {
				if (l[1] == r[1]) return sarr[i - 1][l[0]] > sarr[i - 1][r[0]];
				return l[1] < r[1];
			});
			//sarr.push_back(darray[1]);
			for (int k = 0; k < l; ++k) sarr[i][k] = darray[k][0];
		}


		// make answer
		vector<int> ans;
		for (auto it : queries) {
			ans.push_back(sarr[it[1] - 1][it[0] - 1]);
		}
		return ans;
	}
};

class Solution {
public:
	vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
		int l = nums.size();
		int dsize = nums[0].size();
		vector<vector<int>>  sarr(dsize, vector<int>(l, 0));
		vector<int> rank(l, 0);

		vector<int> ans;

		if (l == 1) {
			for (auto it : queries) {
				ans.push_back(0);
			}
			return ans;
		}

		// first soft array 
		vector<vector<int>> darray;
		for (int i = 0; i < l; ++i) {
			darray.push_back({ i, nums[i][dsize - 1] - '0' });
		}

		sort(darray.begin(), darray.end(), [](vector<int> &l, vector<int> &r) {
			if (l[1] == r[1]) return l[0] < r[0];
			return l[1] < r[1];
		});

		//sarr.push_back(darray[1]);
		for (int i = 0; i < l; ++i) {
			sarr[0][i] = darray[i][0];
			rank[darray[i][0]] = i;
		}

		for (int i = 1; i < dsize; ++i) {
			vector<vector<int>> darray;
			for (int j = 0; j < l; ++j) {
				darray.push_back({ j, nums[j][dsize - 1 - i] - '0' });
			}

			sort(darray.begin(), darray.end(), [&](vector<int> &l, vector<int> &r) {
				if (l[1] == r[1]) {
					//return sarr[i - 1][l[0]] > sarr[i - 1][r[0]];
					return rank[l[0]] < rank[r[0]];
				}
				return l[1] < r[1];
			});
			//sarr.push_back(darray[1]);
			for (int k = 0; k < l; ++k) {
				sarr[i][k] = darray[k][0];
				rank[darray[k][0]] = k;
			}
		}


		// make answer

		for (auto it : queries) {
			ans.push_back(sarr[it[1] - 1][it[0] - 1]);
		}
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	//vector<string> nums = { "102", "473", "251", "814" };
	//vector<vector<int>> queries = { {1,1}, {2,3}, {4,2}, {1,2} };

	vector<string> nums = { "9415","5908","1840","5307" };
	vector<vector<int>> queries = {{3, 2}, {2, 2}, {3, 3}, {1, 3}};

	//vector<string> nums = { "803", "233", "246" };
	//vector<vector<int>> queries = { {1,3} };

	vector<int> ans = sol.smallestTrimmedNumbers(nums, queries);

	for (auto it : ans) {
		cout << it << " ";
	}

	cin >> c;

}