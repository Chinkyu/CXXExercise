//  map processing . and long long is tricky
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
	vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
		int l = creators.size();
		
		unordered_map<string, int> tsum;
		unordered_map<string, pair<string, int>>  max_each;

		for (int i = 0; i < l; ++i) {
			tsum[creators[i]] += views[i];

			if (max_each.find(creators[i]) == max_each.end()) {
				max_each[creators[i]] = make_pair(ids[i], views[i]);
			}
			else {
				if (max_each[creators[i]].second < views[i]) {
					max_each[creators[i]] = make_pair(ids[i], views[i]);
				}
				else if (max_each[creators[i]].second == views[i]) {
					if (max_each[creators[i]].first > ids[i]) {
						max_each[creators[i]] = make_pair(ids[i], views[i]);
					}
				}
			}
		}

		// find maxes
		vector<string> max_str;
		int max_view = 0;
		for (auto it : tsum) {
			if (it.second > max_view) {
				max_str.clear();
				max_str.push_back(it.first);
				max_view = it.second;
			}
			else if (it.second == max_view) {
				max_str.push_back(it.first);
			}
			else {

			}
		}

		vector<vector<string>> ans;
		for (auto it : max_str) {
			ans.push_back({ it, max_each[it].first });
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;
	vector<string> creators = { "alice","bob","alice","chris" };
	vector<string> ids = { "one","two","three","four" };
	vector<int> views = { 5,10,5,4 };

	vector<vector<string>> ans = sol.mostPopularCreator(creators, ids, views);

	for (auto it : ans) {
		cout << it[0] << " " << it[1] << endl;
	}
	cin >> c;
}