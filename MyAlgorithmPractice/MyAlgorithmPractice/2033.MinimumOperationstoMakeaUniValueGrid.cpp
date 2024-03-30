//  답봤음 : median 값이 제일 가까운 거리라는데..
// 아래 논리는 같은 값이 없다는 가정하에서 가능한 것임. 
// https://asvrada.github.io/blog/median-shortest-distance-sum/
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

// median is solution ??? if it has median 
class Solution {
public:
	int distance(vector<int> &v, int num) {
		int ans = 0;
		for (auto &it : v) {
			ans += abs(it - num);
		}
		return ans;
	}


	int minOperations(vector<vector<int>>& grid, int x) {
		vector<int> v;

		int tmin = INT_MAX, tmax = 0;
		for (auto &it : grid) {
			for (auto &jt : it) {
				tmin = min(tmin, jt);
				tmax = max(tmax, jt);
			}
		}

		long long sum = 0;
		for (auto &it : grid) {
			for (auto &jt : it) {
				if ((jt - tmin) % x != 0) return -1;
				v.push_back((jt - tmin) / x);
				sum += (jt - tmin) / x;
			}
		}


		// binary search 
		sort(v.begin(), v.end());

		return distance(v, v[v.size()/2]);
	}
};


// some error 
class _Solution {
public:
	int distance(vector<int> &v, int num) {
		int ans = 0;
		for (auto &it : v) {
			ans += abs(it - num);
		}
		return ans;
	}


	int minOperations(vector<vector<int>>& grid, int x) {
		vector<int> v;

		int tmin = INT_MAX, tmax = 0;
		for (auto &it : grid) {
			for (auto &jt : it) {
				tmin = min(tmin, jt);
				tmax = max(tmax, jt);
			}
		}

		long long sum = 0;
		for (auto &it : grid) {
			for (auto &jt : it) {
				if ((jt - tmin) % x != 0) return -1;
				v.push_back((jt - tmin)/x);
				sum += (jt - tmin) / x;
			}
		}


		// binary search 
		sort(v.begin(), v.end());

		int len = v.size();
		int l = 0, r = v[len - 1];

		int ld = 0, rd = 0;
		while (l < r) {
			ld = distance(v, l);
			rd = distance(v, r);

			if (l + 1 == r) {
				ld = min(ld, rd);
				break;
			}

			if (ld <= rd) {
				r = (l + r) / 2;
			}
			else {
				l = (l + r) / 2;
			}
		}
		
		return ld;
	}
};

int main() {
	char c;
	Solution sol;

	vector<vector<int>> grid = { {1, 5}, {2, 3} }; //{{2, 4}, {6, 8}};

	cout << sol.minOperations(grid, 1);

	cin >> c;
}