//  ¥‰∫√¿Ω : recursion... .
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

// not work
class _Solution {
public:
	int distributeCookies(vector<int> & cookies, int k) {
		int l = cookies.size();
		// min priority queue
		priority_queue<int, vector<int>, greater<int>> minq;

		for (int i = 0; i < k; ++i) {
			minq.push(0);
		}

		sort(cookies.begin(), cookies.end());

		for (int i = l - 1; i >= 0; --i) {
			int t = minq.top();
			minq.pop();
			minq.push(t + cookies[i]);
		}

		int tmax = 0;
		while (!minq.empty()) {
			int t = minq.top();
			minq.pop();
			tmax = max(tmax, t);
		}
		return tmax;
	}
};

class Solution {
public:
	int k, res = INT_MAX;
	vector<int> d = { 0, 0, 0, 0, 0, 0, 0, 0 };

	void S(vector<int> cookies, int index, int f) {
		if (index == cookies.size()) {
			int curr = 0;
			for (int i = 0; i < k; i++) curr = max(curr, d[i]);
			res = min(res, curr);
			return;
		}

		for (int i = 0; i < f; i++) {
			d[i] += cookies[index];
			S(cookies, index + 1, f);
			d[i] -= cookies[index];
		}

		if (f < k) {
			d[f] += cookies[index];
			S(cookies, index + 1, f + 1);
			d[f] -= cookies[index];
		}

	}

	int distributeCookies(vector<int>& cookies, int K) {
		k = K;
		S(cookies, 0, 0);
		return res;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> cookies = { 8, 15, 10, 20, 8 };
	cout << sol.distributeCookies(cookies, 2);

	cin >> c;

}