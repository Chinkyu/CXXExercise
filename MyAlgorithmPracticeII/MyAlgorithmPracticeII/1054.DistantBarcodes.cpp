// 답봤음 : 너무 간단한 방법이 있었음... 얼탱..   
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>
#include <set>
#include <list>
#include <regex>
#include <memory>

using namespace std;

// timeout 
class _Solution {
public:
	vector<int> rearrangeBarcodes(vector<int>& barcodes) {

		unordered_map<int, int> m;

		for (auto& it : barcodes) {
			m[it]++;
		}

		vector<pair<int, int>> vp;

		for (auto& it : m) {
			vp.push_back(make_pair(it.first, it.second));
		}

		sort(vp.begin(), vp.end(), [](pair<int, int>& pl, pair<int, int>& pr) {
			return pl.second > pr.second;
		});

		vector<int> ans;

		do {
			ans.push_back(vp[0].first);
			vp[0].second--;

			if (vp.size() >= 2) {
				ans.push_back(vp[1].first);
				vp[1].second--;
			}

			sort(vp.begin(), vp.end(), [](pair<int, int>& pl, pair<int, int>& pr) {
				return pl.second > pr.second;
				});

			while (vp.size() > 0 && vp[vp.size() -1].second == 0) {
				vp.pop_back();
			}
			
		} while (!vp.empty());

		return ans;
	}
};

// using heap -> 이것 가지고도  timeout 임.... 
class Solution {
public:
	vector<int> rearrangeBarcodes(vector<int>& barcodes) {

		unordered_map<int, int> m;

		for (auto& it : barcodes) {
			m[it]++;
		}

		vector<pair<int, int>> vp;

		for (auto& it : m) {
			vp.push_back(make_pair(it.first, it.second));
		}

		vector<int> ans;

		make_heap(vp.begin(), vp.end(), [](pair<int, int>& pl, pair<int, int>& pr) {
			return pl.second < pr.second;
			});

		do {

			ans.push_back(vp[0].first);
			vp[0].second--;

			pop_heap(vp.begin(), vp.end(), [](pair<int, int>& pl, pair<int, int>& pr) {
				return pl.second < pr.second;
				});

			if (vp[0].second != 0) {
				ans.push_back(vp[0].first);
				vp[0].second--;
			}

			make_heap(vp.begin(), vp.end(), [](pair<int, int>& pl, pair<int, int>& pr) {
				return pl.second < pr.second;
				});

//			while (vp.size() > 0 && vp[vp.size() - 1].second == 0) {
//				vp.pop_back();
//			}

		} while (vp[0].second != 0);

		return ans;
	}
};

class Solution {
public:
	vector<int> rearrangeBarcodes(vector<int>& b, int pos = 0) {
		unordered_map<int, int> m;
		set<pair<int, int>> s;
		for (auto n : b) ++m[n];
		for (auto it = begin(m); it != end(m); ++it) s.insert({ it->second, it->first });
		for (auto it = s.rbegin(); it != s.rend(); ++it) {
			for (auto cnt = 0; cnt < it->first; ++cnt, pos += 2) {
				if (pos >= b.size()) pos = 1;
				b[pos] = it->second;
			}
		}
		return b;
	}
};

int main() {
	char c;
	Solution sol;
	vector<int> barcodes = { 1, 1, 2 };
	//vector<int> arr = { 60864,25176,27249,21296,20204 };

	vector<int> ans = sol.rearrangeBarcodes(barcodes);

	for (auto& it : ans) {
		cout << it << " ";
	}

	cin >> c;
}