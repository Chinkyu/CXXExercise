// 답봤음 :  h 가 100 개 까지 된다는 limit 때문에 문제 성립 가능 
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <iomanip>

using namespace std;

class Solution {
public:
	vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
		vector<vector<int>> umap(101);
		for (auto &r : rectangles) {
			umap[r[1]].push_back(r[0]);
		}

		for (int i = 0; i < 101; i++) {
			sort(begin(umap[i]), end(umap[i]));
		}

		vector<int> res;
		for (auto &p : points) {
			int sum = 0;
			for (int i = p[1]; i < 101; i++) {
				auto lb = lower_bound(begin(umap[i]), end(umap[i]), p[0]);
				sum += end(umap[i]) - lb;
			}
			res.push_back(sum);
		}
		return res;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> nums = { 4, 2, 0 }; // { 2, 5, 3, 9, 5, 3 };

	cout << sol.minimumAverageDifference(nums);

	cin >> c;

}