// its OK : 
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

using namespace std;

class Solution {
public:

	bool checkExit(vector<int>& entrance, int lr, int lc, vector<int>& position) {

		if (entrance != position && (position[0] == 0 || position[0] == lr - 1)) return true;
		if (entrance != position && (position[1] == 0 || position[1] == lc - 1)) return true;
		return false;

	}
	int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
		int lr = maze.size();
		int lc = maze[0].size();
		set<vector<int>> us, tus;

		us.insert(entrance);
		//maze[entrance[0]][entrance[1]] = 0;
		int step = 1;

		while (us.size() != 0) {
			tus.clear();

			for (auto& it : us) {

				// left it[1] - 1
				if (it[1]-1 >= 0 && maze[it[0]][it[1]-1] == '.') {
					vector<int> next({ it[0], it[1] - 1 });
					if (checkExit(entrance, lr, lc, next)) return step;

					maze[it[0]][it[1]-1] = '.' + step;
					tus.insert(next);
				}
				// up it[0] - 1
				if (it[0]-1 >= 0 && maze[it[0]-1][it[1]] == '.') {
					vector<int> next({ it[0] - 1, it[1] });
					if (checkExit(entrance, lr, lc, next)) return step;

					maze[it[0]-1][it[1]] = '.' + step;
					tus.insert(next);
				}
				// right it[1] + 1
				if (it[1] + 1 < lc && maze[it[0]][it[1]+1] == '.') {
					vector<int> next({ it[0], it[1] + 1 });
					if (checkExit(entrance, lr, lc, next)) return step;

					maze[it[0]][it[1]+1] = '.' + step;
					tus.insert(next);
				}
				// down it[0] + 1
				if (it[0]+1 < lr && maze[it[0]+1][it[1]] == '.') {
					vector<int> next({ it[0] + 1, it[1] });
					if (checkExit(entrance, lr, lc, next)) return step;

					maze[it[0]+1][it[1]] = '.' + step;
					tus.insert(next);
				}

			}

			us = tus;
			step++;
		}

		return -1;

	}
};

int main() {
	char c;
	Solution sol;

	vector<vector<char>> maze = 
	{ {'.', '+', '+', '+', '+'}, 
	  {'.', '+', '.', '.', '.'}, 
	  {'.', '+', '.', '+', '.'}, 
	  {'.', '.', '.', '+', '.'}, 
	  {'+', '+', '+', '+', '.'}};
	//{ {'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'} };

	vector<int> entrance = { 0, 0 };
	cout << sol.nearestExit(maze, entrance);

	cin >> c;
}