//  OK :   다해보기로 되었음.. 
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
	int score(vector<vector<int>>& students, vector<vector<int>>& mentors, vector<int> &mentorAssign) {
		int lr = students.size(), lc = students[0].size();

		int tScore = 0;
		for (int i = 0; i < lr; ++i) {
			int t = 0;
			for (int j = 0; j < lc; ++j) {
				t += students[i][j] == mentors[mentorAssign[i]][j];
			}

			tScore += t;
		}
		
		return tScore;
	}


	int tmax = 0;

	int traverse(vector<vector<int>>& students, vector<vector<int>>& mentors, 
		vector<bool> &used, vector<int> &mentorAssign, int depth) {
		int l = students.size();

		if (depth >= l) {
			tmax = max(tmax, score(students, mentors, mentorAssign));
			return 0;
		}
		int score = 0;

		for (int i = 0; i < l; ++i) {
			if (used[i] == false) {
				mentorAssign[depth] = i;
				used[i] = true;
				traverse(students, mentors, used, mentorAssign, depth + 1);
				mentorAssign[depth] = -1;
				used[i] = false;
			}
		}
		return 0;
	}

	int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
		int l = students.size();

		tmax = 0;
		vector<int> mentorAssign(l, -1);
		vector<bool> used(l, false);

		traverse(students, mentors, used, mentorAssign, 0);
		return tmax;
	}
};

int main() {
	char c;
	Solution sol;

//	vector<vector<int>> students = {{1, 1, 0}, {1, 0, 1}, {0, 0, 1}};
//	vector<vector<int>> mentors = {{1, 0, 0}, {0, 0, 1}, {1, 1, 0}};

	vector<vector<int>> students = { {0, 0}, {0, 0}, {0, 0} };
	vector<vector<int>> mentors = { {1, 1}, {1, 1}, {1, 1} };

	cout << sol.maxCompatibilitySum(students, mentors);

	cin >> c;
}