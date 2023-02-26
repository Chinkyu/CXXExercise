// 그냥 무식하게 따라가면 안되고..
//  테두리를 둘면서...  2(w-1) + 2(h-1)  로 하면서  right, up, left, down  으로 수식으로 계산해서
// 풀어야 타임아웃이 안됨. 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

// Enhance for timelimit
class Robot {
public:
	int w, h;
	int x, y, d;
	int count;
	Robot(int width, int height) : w(width), h(height) {
		x = 0;
		y = 0;
		d = 1;       // 1 right, 2 down, 3 left, 4 up
		count = 0;
	}

	void step(int num) {

		count = (count + num) % (2 * (w - 1) + 2 * (h - 1));

		if (0 <= count && count <= w - 1) {
			// right
			x = count;
			y = 0; 
			d = (count == 0) ? 4 : 1;  // trick... !!! 
		}
		else if (w - 1 < count && count <= (w - 1) + (h - 1)) {
			// up
			x = w - 1;
			y = count - (w - 1);
			d = 2;
		}
		else if ((w - 1) + (h - 1) < count && count <= 2 * (w - 1) + (h - 1)) {
			// left
			x = (w - 1) - (count - ((w - 1) + (h - 1)));
			y = h - 1;
			d = 3;
		}
		else {
			// down
			x = 0;
			y = (h - 1) - (count - (2 * (w - 1) + (h - 1)));
			d = 4;
		}
	}

	vector<int> getPos() {
		return vector<int>({ x, y });
	}

	string getDir() {
		switch (d) {
		case 1:
			return "East";
			break;
		case 2:
			return "North";
			break;
		case 3:
			return "West";
			break;
		case 4:
			return "South";
			break;
		}
		return "East";
	}
};

// Enhance for timelimit - fail
class Robot2 {
public:
	int w, h;
	int x, y, d;
	Robot2(int width, int height) : w(width), h(height) {
		x = 0;
		y = 0;
		d = 1;       // 1 right, 2 down, 3 left, 4 up
	}

	void step(int num) {
		int rstep = num;

		while (rstep != 0) {
			switch (d) {
			case 1: // right 
				if (x < w - 1) {
					if (rstep < w - 1 - x) {
						x += rstep;
						rstep = 0;
					}
					else {
						rstep -= w - 1 - x;
						x = w - 1;
						d = 2;
					}
				}
				else {
					d = 2;
				}
				break;
			case 2: // down
				if (y < h - 1) {
					if (rstep < h - 1 - y) {
						y += rstep;
						rstep = 0;
					}
					else {
						rstep -= h - 1 - y;
						y = h - 1;
						d = 3;
					}
				}
				else {
					d = 3;
				}
				break;
			case 3: // left
				if (0 < x) {
					if (rstep < x) {
						x -= rstep;
						rstep = 0;
					}
					else {
						rstep -= x;
						x = 0;
						d = 4;
					}
				}
				else {
					d = 4;
				}
				break;
			case 4: // up
				if (0 < y) {
					if (rstep < y) {
						y -= rstep;
						rstep = 0;
					}
					else {
						rstep -= y;
						y = 0;
						d = 0;
					}
				}
				else {
					d = 0;
				}
				break;
			}
		}
	}

	vector<int> getPos() {
		return vector<int>({ x, y });
	}

	string getDir() {
		switch (d) {
		case 1:
			return "East";
			break;
		case 2:
			return "North";
			break;
		case 3:
			return "West";
			break;
		case 4:
			return "South";
			break;
		}
		return "East";
	}
};


class _Robot {
public:
	int w, h;
	int x, y, d;
	_Robot(int width, int height) : w(width), h(height) {
		x = 0;
		y = 0; 
		d = 1;       // 1 right, 2 down, 3 left, 4 up
	}

	void step(int num) {
		int rstep = num;

		while (rstep != 0) {
			switch (d) {
			case 1: // right 
				if (x < w - 1) {
					x++;
					rstep--;
				}
				else {
					d = 2;
				}
				break;
			case 2: // down
				if (y < h - 1) {
					y++;
					rstep--;
				}
				else {
					d = 3;
				}
				break;
			case 3: // left
				if (0 < x) {
					x--;
					rstep--;
				}
				else {
					d = 4;
				}
				break;
			case 4: // up
				if (0 < y) {
					y--;
					rstep--;
				}
				else {
					d = 0;
				}
				break;
			}
		}
	}

	vector<int> getPos() {
		return vector<int>({ x, y });
	}

	string getDir() {
		switch (d) {
		case 1:
			return "East";
			break;
		case 2:
			return "North";
			break;
		case 3:
			return "West";
			break;
		case 4:
			return "South";
			break;
		}
		return "East";
	}
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */

int main() {
	char c;

//	Solution sol;

//	vector<int> parents = { -1, 2, 0, 2, 0 };

//	cout << sol.countHighestScoreNodes(parents) << endl;
	//	cout << "test : " << ans << endl;

	cin >> c;
}