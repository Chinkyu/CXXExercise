// Easy 
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
	vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
		sort(score.begin(), score.end(), [k](vector<int> & l, vector<int> & r) {
			return l[k] > r[k];
		});
		return score;
	}
};

int main() {
	char c;

	Solution sol;

	vector<vector<int>> score = { {10, 6, 9, 1},{7, 5, 11, 2},{4, 8, 3, 15} };
	vector<vector<int>> ans = sol.sortTheStudents(score, 2);

	for (auto it : ans) {
		for (auto jt : it) {
			cout << jt;
		}
		cout << endl;
	}

	cin >> c;
}