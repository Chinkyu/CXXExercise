//  Bitmap solution : 답보고 이해 했음.... 이건 좀 대단한데..
//  Bitmap  으로 지금 까지 모든 수에 대해서 합을 구하는것 하고 같은 효과가 있음..... !!! 
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

// from answer
class Solution {
public:
	int minimizeTheDifference(vector<vector<int>>& mat, int target) {
		bitset<5000> p(1);
		for (auto& r : mat) {
			bitset<5000> tmp;
			for (auto& i : r) {
				tmp = tmp | (p << i);
			}
			swap(p, tmp);
		}
		int res = 10000;
		for (int i = 0; i < 5000; ++i) {
			if (p[i]) res = min(res, abs(i - target));
		}
		return res;
	}
};



class _Solution {
public:
	int ans = INT_MAX;
	void traverse(vector<vector<int>> &mat, int idx, int sub_sum, int len, int target) {

		if (ans == 0) return;  // find answer return for all 

		if (idx == len) {
			if (abs(sub_sum - target) < ans) ans = abs(sub_sum - target);
			return;
		}

		for (int i = 0; i < mat[idx].size(); ++i) {
			if (sub_sum - target > ans) continue;
			traverse(mat, idx + 1, sub_sum + mat[idx][i], len, target);
		}
	}

	int minimizeTheDifference(vector<vector<int>>& mat, int target) {
		ans = INT_MAX;
		int len = mat.size();
		
		traverse(mat, 0, 0, len, target);

		return ans;
	}
};

int main() {
	char c;

	Solution sol;
	vector<vector<int>> m = { {1, 2, 3}, { 4, 5, 6 }, { 7, 8, 9 }};

	cout << sol.minimizeTheDifference(m, 13) << endl;
	//	cout << "test : " << ans << endl;

	cin >> c;
}