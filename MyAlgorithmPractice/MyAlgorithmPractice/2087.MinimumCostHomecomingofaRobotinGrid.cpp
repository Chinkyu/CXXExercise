//  어이없군....   단거리가 답임... 어짜피 왔다갔다 해도 같으니까 그런것임. 
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
	int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
		long long ct = 0;
		long long x1 = startPos[0], y1 = startPos[1], x2 = homePos[0], y2 = homePos[1];
		while (x1 < x2) ct += rowCosts[++x1];
		while (x1 > x2) ct += rowCosts[--x1];
		while (y1 < y2) ct += colCosts[++y1];
		while (y1 > y2) ct += colCosts[--y1];

		return ct;
	}
};

//  이것 이렇게 풀면 timeout  ->  dijkstra로 풀어야함...  -> 아님 직선이 재일 적게 든다고함. 
class Solution {
public:
	vector<vector<int>> vMap;
	int rl = 0;
	int cl = 0;

	int sr = 0;
	int sc = 0;
	int er = 0;
	int ec = 0;
	int minw = INT_MAX;

	int rd = 0;
	int cd = 0;

	void traverse(int r, int c, int w, vector<int>& rowCosts, vector<int>& colCosts) {

		if (w > minw) return;
		if (sr <= er) {
			if (!((sr <= r) && (r <= er)) &&
				((sc <= c) && (c <= ec))) return;
		}
		else {
			if (!((er <= r) && (r <= sr)) &&
				((ec <= c) && (c <= sc))) return;
		}

		if (er == r && ec == c) {
			if (w < minw) minw = w;
			return;
		}

		// -r
		if (rd == -1 && 0 <= r - 1) {
			if (vMap[r - 1][c] != 1) {
				vMap[r - 1][c] = 1;
				traverse(r - 1, c, w + rowCosts[r-1], rowCosts, colCosts);
				vMap[r - 1][c] = 0;
			}
		}
		// +r
		if (rd == 1 && r + 1 < rl) {
			if (vMap[r + 1][c] != 1) {
				vMap[r + 1][c] = 1;
				traverse(r + 1, c, w + rowCosts[r + 1], rowCosts, colCosts);
				vMap[r + 1][c] = 0;
			}
		}

		// -c
		if (cd == -1 && 0 <= c - 1) {
			if (vMap[r][c - 1] != 1) {
				vMap[r][c - 1] = 1;
				traverse(r, c - 1, w + colCosts[c - 1], rowCosts, colCosts);
				vMap[r][c - 1] = 0;
			}
		}

		// +c
		if (cd == 1 && c + 1 < cl) {
			if (vMap[r][c + 1] != 1) {
				vMap[r][c + 1] = 1;
				traverse(r, c + 1, w + colCosts[c + 1], rowCosts, colCosts);
				vMap[r][c + 1] = 0;
			}
		}
	}

	int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
		rl = rowCosts.size();
		cl = colCosts.size();

		sr = startPos[0];
		sc = startPos[1];
		er = homePos[0];
		ec = homePos[1];
			
		if ((homePos[0] - startPos[0]) > 0) {
			rd = 1;
		}
		else if ((homePos[0] - startPos[0]) < 0) {
			rd = -1;
		}

		if ((homePos[1] - startPos[1]) > 0) {
			cd = 1;
		}
		else if ((homePos[1] - startPos[1]) < 0) {
			cd = -1;
		}


		minw = INT_MAX;
		vMap = vector<vector<int>>(rl, vector<int>(cl, 0));

		traverse(startPos[0], startPos[1], 0, rowCosts, colCosts);
		return minw;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> startPos = { 6, 3 }; // { 2, 2 }; // { 1, 0 };
	vector<int> homePos = { 3, 3 }; // { 1, 4 }; // { 2, 3 };
	vector<int> rowCosts = { 6,3,4,4,10,2,14,21 }; // { 1, 0, 21, 18 }; // { 5, 4, 3 };
	vector<int> colCosts = { 7,2,3,3,15 }; // { 9, 4, 1, 2, 13, 18, 14, 23 }; // { 8, 2, 6, 7 };

	cout << sol.minCost(startPos, homePos, rowCosts, colCosts);

	cin >> c;
}