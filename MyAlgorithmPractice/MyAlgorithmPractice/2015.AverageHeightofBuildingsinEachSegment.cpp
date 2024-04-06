//  ¥‰∫√¿Ω....  
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;


class Solution {
public:
vector<vector<int>> averageHeightOfBuildings(vector<vector<int>>& buildings) {
	vector<vector<int>> res, pts;
	for (auto b : buildings) {
		pts.push_back({ b[0], b[2] });
		pts.push_back({ b[1], -b[2] });
	}
	sort(begin(pts), end(pts));
	int h = 0, cnt = 0;
	for (int i = 0, j = 0; i < pts.size(); i = j) {
		if (h)
			res.back()[1] = pts[i][0];
		for (j = i; j < pts.size() && pts[i][0] == pts[j][0]; ++j) {
			h += pts[j][1];
			cnt += pts[j][1] > 0 ? 1 : -1;
		}
		if (h && (res.empty() || res.back()[1] != pts[i][0] || res.back()[2] != h / cnt))
			res.push_back({ pts[i][0], pts[i][0], h / cnt });
	}
	return res;
}
}

class _Solution {
public:
	vector<vector<int>> averageHeightOfBuildings(vector<vector<int>>& buildings) {
		vector<pair<int, int>> v;

		for (auto &it : buildings) {
			v.push_back(make_pair(it[0], it[2]));
			v.push_back(make_pair(it[1], it[2] * -1));
		}

		sort(v.begin(), v.end());

/*
		vector<pair<int, int>> v2;
		// remove duplicate
		v2.push_back(v[0]);
		int idx = 0;
		for (int i = 1; i < v.size(); ++i) {
			if (v[idx].first == v[i].first) {
				v2[idx].second += v[i].second;
			}
			else {
				v2.push_back(v[i]);
				idx++;
			}
		}
*/
		vector<vector<int>> ans;
		int layer = 0, sum = 0;
		int preIdx = v[0].first, preHeight = v[0].second;
		for (auto &it : v) {
			if (it.second > 0) {
				if (preIdx != it.first && sum != 0 && sum/layer != preHeight) {
					ans.push_back({ preIdx, it.first, sum / layer });
					preHeight = sum / layer;
					preIdx = it.first;
				}
				layer++;
				sum += it.second;


			}
			else {
				if (preIdx != it.first && sum != 0 && sum / layer != preHeight) {
					ans.push_back({ preIdx, it.first, sum / layer });
					preHeight = sum / layer;
					preIdx = it.first;
				}
				layer--;
				sum += it.second;
			}
		}

		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	vector<vector<int>> buildings = { {1,3,2},{2,5,3},{2,8,3 }
};

	vector<vector<int>> ans = sol.averageHeightOfBuildings(buildings);

	for (auto &it : ans) {
		cout << it[0] << " " << it[1] << " " << it[2] << endl;
	}

	cin >> c;
}