// easy.. : just do.. 
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
	int numberOfCleanRooms(vector<vector<int>>& room) {
		int cl = room.size(), rl = room[0].size();
		int direction = 0;

		int c = 0, r = 0;

		int ans = 1;
		room[c][r] = -1;


		int retry = 0;

		while(retry < 6) {
			direction %= 4;
			retry++;
			switch (direction) {
			case 0:	// right
				r++;
				if (rl <= r || room[c][r] == 1) {
					r--;
					direction++;
					continue;
				}
				break;
			case 1: // down
				c++;
				if (cl <= c || room[c][r] == 1) {
					c--;
					direction++;
					continue;
				}
				break;
			case 2:	// left
				r--;
				if (r < 0 || room[c][r] == 1) {
					r++;
					direction++;
					continue;
				}
				break;
			case 3:	// up
				c--;
				if (c < 0 || room[c][r] == 1) {
					c++;
					direction++;
					continue;
				}
				break;
			}

			if (room[c][r] == 0) {
				room[c][r] = -1;
				ans++;
				retry = 0;
			}

		};

		return ans;
	}
};



int main() {
	char c;
	Solution sol;

	//vector<vector<int>> room = {{0, 0, 0}, {1, 1, 0}, {0, 0, 0}};
	//vector<vector<int>> room = { {0, 1, 0}, {1, 0, 0}, {0, 0, 0} };
	vector<vector<int>> room = { {0, 0, 0, 0, 0, 1, 0, 0} };

	cout << sol.numberOfCleanRooms(room);

	cin >> c;
}