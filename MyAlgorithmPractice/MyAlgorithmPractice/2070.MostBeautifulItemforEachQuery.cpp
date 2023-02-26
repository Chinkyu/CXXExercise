//  몇가지 장애가 있었음
//  low_bound 를 가지고 낮은 index 찾는법
//  그리고 map 이 줄어 들지 않아야 한다는것은...  추후에 알게됨..... !!!!! 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
		int len = queries.size();
		map<int, int> m;
		vector<int> ans(len, 0);

		for (auto it : items) {
			if (m.find(it[0]) != m.end()) {
				if (m[it[0]] < it[1]) m[it[0]] = it[1];
			}
			else {
				m[it[0]] = it[1];
			}
		}

		// make map increase.. there is no decrease.. due to nature 
		int prev = 0;
		for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
			if (it->second < prev) it->second = prev;
			prev = it->second;
		}


		for (int i = 0; i < len; ++i) {
			if (m.find(queries[i]) != m.end()) {
				ans[i] = m[queries[i]];
			}
			else {
				auto it = m.lower_bound(queries[i]);
				if (it == m.end()) --it;
				while ((*it).first > queries[i] && it != m.begin()) it--;

				if (it == m.begin() && (*it).first > queries[i]) {
					ans[i] = 0;
				}
				else {
					ans[i] = (*it).second;
				}
			}
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

//	vector<vector<int>> items = { {1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5} };
//	vector<int> queries = { 1, 2, 3, 4, 5, 6 };

//	vector<vector<int>> items = { {1, 2}, {1, 2}, {1, 3}, {1, 4}};
//	vector<int> queries = { 1};

	vector<vector<int>> items = {{193, 732}, {781, 962}, {864, 954}, {749, 627}, {136, 746}, {478, 548}, {640, 908}, {210, 799}, {567, 715}, {914, 388}, {487, 853}, {533, 554}, {247, 919}, {958, 150}, {193, 523}, {176, 656}, {395, 469}, {763, 821}, {542, 946}, {701, 676}};
	vector<int> queries = {885, 1445, 1580, 1309, 205, 1788, 1214, 1404, 572, 1170, 989, 265, 153, 151, 1479, 1180, 875, 276, 1584};

	vector<int> ans = sol.maximumBeauty(items, queries);

	for (auto it : ans) {
		cout << " " << it;
	}
	cout << endl;
	//	cout << sol.countHighestScoreNodes(parents) << endl;
		//	cout << "test : " << ans << endl;

	cin >> c;
}