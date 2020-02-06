#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		map<int, int> im;
		vector<int> ans;

		for (auto it : nums) {
			im[it]++;
		}

		vector <pair<int, int>> pr;
		for (auto it : im) {
			pr.push_back(it);
		}

		sort(pr.begin(), pr.end(), 
			[=](pair<int, int>& a, pair<int, int>& b) {
				return a.second > b.second;
			}
		);

		for (int i = 0; i < k; i++) {
			ans.push_back(pr[i].first);
		}
		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> n = 
	//{ 1, 1, 1, 2, 2, 3 };
	{ 1, 1, 2, 2, 2, 3, 3, 3, 3, 3 };
	//{ 4, 1, -1, 2, -1, 2, 3 };
	vector<int> ans = sol.topKFrequent(n, 2);

	for (auto it : ans) {
		cout << it << " ";
	}
	cin >> c;
}