#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class _Solution {
public:
	vector<vector<int>> & r;
	int sx, ex, sy, ey;
	int xd, yd;
	_Solution(vector<vector<int>>& rects) : r(rects)  {
		srand(time(NULL));

		sx = sy = INT_MAX;
		ex = ey = INT_MIN;

		for (auto it : rects) {
			if (it[0] > it[2]) {
				if (it[0] > ex) ex = it[0];
				if (it[2] < sx) sx = it[2];
			}
			else { // it[0] <= it[2]
				if (it[2] > ex) ex = it[2];
				if (it[0] < sx) sx = it[0];
			}

			if (it[1] > it[3]) {
				if (it[1] > ey) ey = it[1];
				if (it[3] < sy) sy = it[3];
			}
			else { // it[1] <= it[3]
				if (it[3] > ey) ey = it[3];
				if (it[1] < sy) sy = it[1];
			}
		}

		xd = ex - sx;
		yd = ey - sy;

	}

	bool isInside(int x, int y) {

		for (auto it : r) {
			if ((it[0] <= x && x <= it[2]) &&
				(it[1] <= y && y <= it[3])) {
				return true;
			}
		}
		return false;
	}

	vector<int> pick() {
		int x, y;
		vector<int> ans;
		do {
			x = sx + rand() % xd;
			y = sy + rand() % yd;

		} while (!isInside(x, y));

		ans.push_back(x);
		ans.push_back(y);
		return ans;
	}
};

class Solution {
public:
	vector<vector<int>> & r;
	vector<int> size;
	long long total_size;
	int sx, ex, sy, ey;
	//int xd, yd;
	Solution(vector<vector<int>>& rects) : r(rects) {
		srand(time(NULL));

		sx = sy = INT_MAX;
		ex = ey = INT_MIN;

		total_size = 0;
		int t = 0;
		for (auto it : rects) {
			t = (it[2] - it[0]) * (it[3] - it[1]);

			total_size += t;
			size.push_back(total_size);
		}

		for (int i = 0; i < size.size(); ++i) {
			size[i] = size[i] * 100 / total_size;
		}
		total_size = 100;

	}

	vector<int> pick() {
		int x, y;
		vector<int> ans;

		int select = rand() % total_size;
		int c = 0;
		for (int i = 0; i < size.size(); i++) {
			if (select < size[i]) {
				c = i;
				break;
			}
		}

		//(it[2] - it[0]) * (it[3] - it[1])
		int dx = r[c][2] - r[c][0];
		int dy = r[c][3] - r[c][1];

		if (dx != 0) {
			x = r[c][0] + rand() % dx;
		}
		else x = r[c][0];
		if (dy != 0) {
			y = r[c][1] + rand() % dy;
		}
		else y = r[c][1];

		ans.push_back(x);
		ans.push_back(y);
		return ans;
	}
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */

int main() {
	char c;
	//vector<vector<int>> rects = { { 1, 1, 5, 5} };
	//vector<vector<int>> rects = { {35330199, -46858448, 35330694, -46856950} };
	//vector<vector<int>> rects = {{-58953616, -40483558, -58953446, -40482555}, {76369640, 94978791, 76371036, 94979394}, {80970826, -37466957, 80971657, -37466388}, {-79821573, -4177978, -79820536, -4177925}};
	vector<vector<int>> rects = { {-58953616, -40483558, -58953446, -40482555}, { 76369640, 94978791, 76371036, 94979394 }, { 80970826, -37466957, 80971657, -37466388 }, { -79821573, -4177978, -79820536, -4177925 }};
	
	Solution* obj = new Solution(rects);

	for (int i = 0; i < 10; ++i) {
		vector<int> param_1 = obj->pick();
		cout << param_1[0] << " " << param_1[1] << endl;
	}
	cin >> c;
}