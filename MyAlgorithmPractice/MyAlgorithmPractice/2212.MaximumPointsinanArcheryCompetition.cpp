//  翠好澜, 0贸府啊... 包扒... 
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
	vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
		vector<int>v;
		int maxi = 0;
		for (int i = 0; i < (1 << 12); i++) {
			int n = numArrows, cnt = 0;
			vector<int>temp(12, 0);
			for (int j = 11; j >= 0; j--) {
				if (i&(1 << j)) {
					if (n > aliceArrows[j]) {
						n -= (aliceArrows[j] + 1);
						temp[j] = (aliceArrows[j] + 1);
					}
				}
			}
			for (int j = 0; j < 12; j++) {
				if (i&(1 << j)) {
					temp[j] += n;
					break;
				}
			}
			for (int j = 0; j < 12; j++) {
				if (temp[j] > aliceArrows[j]) { cnt += j; }
			}
			if (cnt > maxi) {
				maxi = cnt;
				v = temp;
			}
		}
		return v;
	}
};

class _Solution {
public:

	vector<int> ans = vector<int>(12, 0);
	int maxPoints = 0;
	void traverse(vector<int> &winArray, vector<int> &onoff, int &numArrows, int l, int idx, int sum) {

		if (idx == l) {
			// check
			if (sum == numArrows) {
				// calcurate points
				int points = 0;
				for (int i = 1; i < l; ++i) {
					if (onoff[i] == 1) points += i;
				}

				if (points >= maxPoints) {
					for (int i = 1; i < l; ++i) {
						ans[i] = (onoff[i] == 1) ? winArray[i] : 0;
					}
					maxPoints = points;
				}
			}
			return;
		}

		if (sum > numArrows) return;

		// off
		onoff[idx] = 0;
		traverse(winArray, onoff, numArrows, l, idx + 1, sum);

		// on 
		onoff[idx] = 1;
		sum += winArray[idx];
		traverse(winArray, onoff, numArrows, l, idx + 1, sum);

	}

	vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
		int l = aliceArrows.size();

		maxPoints = 0;
		ans = vector<int>(12, 0);

		vector<int> winArray;
		winArray.push_back(0); // for 0 index 
		for (int i = 1; i < l; ++i) {
			winArray.push_back(aliceArrows[i] + 1);
		}

		vector<int> onoff(l, 0);
		traverse(winArray, onoff, numArrows, l, 1, 0);

		return ans;
	}
};

int main() {
	char c;

	Solution sol;


	vector<int> aliceArrows = { 1,1,0,1,0,0,2,1,0,1,2,0 };
	vector<int> ans = sol.maximumBobPoints(9, aliceArrows);

	for (auto it : ans) {
		cout << it << " ";
	}

	cin >> c;




}