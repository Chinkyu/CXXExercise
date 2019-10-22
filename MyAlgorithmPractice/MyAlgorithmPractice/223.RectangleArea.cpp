#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		vector<int> evt = { A, C, E, G };
		vector<int> ys = { B, D, F, H };

		sort(evt.begin(), evt.end());

		// find min in X 
		int min = B;
		for (auto it : ys) {
			if (min > it) min = it;
		}
		min = -min;   // to baise 0
		B += min; D += min; F += min; H += min;

		vector<int> ys2 = { B, D, F, H };
		// find max in Y
		int max = B;
		for (auto it : ys2) {
			if (max < it) max = it;
		}

		vector<int> vLine(max+1, 0);
		int ans = 0;
		int st = evt[0];


		for (auto it : evt) {

			int count = 0;
			for (auto jt : vLine) {
				if (jt != 0) count++;
			}

			if (it == A) {
				ans += (it - st) * count;
				st = it;
				for (int k = B; k <= D; ++k) vLine[k]++;
			}
			else if (it == E) {
				ans += (it - st) * count;
				st = it;
				for (int k = F; k <= H; ++k) vLine[k]++;
			}
			else if (it == C) {
				ans += (it - st+1) * count;
				st = it + 1;
				for (int k = B; k <= D; ++k) vLine[k]--;
			}
			else if (it == G) {
				ans += (it - st+1) * count;
				st = it + 1;
				for (int k = F; k <= H; ++k) vLine[k]--;
			}
		}
		return ans;
	}
};

int main() {
	Solution sol;
	char c;

	//vector<int> v = { -1, 0, 3, 4, 0, 01, 9, 2 };
	cout << sol.computeArea(-3, 0, 3, 4, 0, -1, 9, 2);

	cin >> c;
}