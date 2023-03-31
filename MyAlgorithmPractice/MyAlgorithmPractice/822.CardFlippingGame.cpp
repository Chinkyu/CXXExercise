//어렵게 생각해서 풀었다가 오래 걸림
// 양쪽에 같은 숫자가 있으면 그수자는  good number 가 될수 없으니까.. 작은 수부터 따지면 쉽게 풀림. 
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
	int flipgame(vector<int>& fronts, vector<int>& backs) {
		vector<int> v;
		map<pair<int, int>, int> m;

		for (auto it : fronts) v.push_back(it);
		for (auto it : backs) v.push_back(it);

		for (int i = 0; i < fronts.size(); ++i) m[make_pair(fronts[i], backs[i])] = 1;

		// sort only in front
		sort(v.begin(), v.end());

		for (int i = 0; i < v.size(); ++i) {
			if (m.find(make_pair(v[i], v[i])) == m.end()) return v[i];
		}

		return 0;
	}
};

class _Solution {
public:
	int flipgame(vector<int>& fronts, vector<int>& backs) {
		vector<pair<int, int>> v(fronts.size(), pair<int,int>(0,0));
		unordered_map<int, int> m;

		for (int i = 0; i < fronts.size(); ++i) {
			if (m.find(fronts[i]) == m.end()) {
				m[fronts[i]] = 1;
			}
			else {
				m[fronts[i]]++;
			}
			v[i] = pair<int, int>(fronts[i], backs[i]);
		}

		// sort only in front
		//sort(v.begin(), v.end());//  , [](pair<int, int> &l, pair<int, int> &r) { l.first < r.first; });

		vector<int> vans;

		for (int i = 0; i < fronts.size(); ++i) {
			int f = v[i].first;
			int b = v[i].second;

			// check before flip
			if (m.find(b) == m.end() || m[b] == 0) vans.push_back(b);

			m[f]--;
			if (m.find(b) == m.end()) m[b] = 1; else m[b]++;

			// check after flip
			if (m[f] == 0) vans.push_back(f);

			// return back m
			m[f]++;
			m[b]--;
		}

		if (vans.size() != 0) {
			sort(vans.begin(), vans.end());
			return vans[0];
		}
		
		return 0;
	}
};

int main() {
	char c;

	Solution sol;

	//vector<int> fronts = { 1, 2, 4, 4, 7 };
	//vector<int> backs = {1, 3, 4, 1, 3};

	vector<int> fronts = { 1 };
	vector<int> backs = { 1};

	cout << sol.flipgame(fronts, backs);


	//	cout << sol.countHighestScoreNodes(parents) << endl;
	//	cout << "test : " << ans << endl;

	cin >> c;
}