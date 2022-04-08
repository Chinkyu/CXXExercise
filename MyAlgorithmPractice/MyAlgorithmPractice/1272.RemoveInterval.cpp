#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

#define IS 0
#define IE 1
#define RS 2
#define RE 3

// how intervals fit for toBeRemoved
//typedef enum {
//	NO_OVERWRAP,
//	RIGHT_OVERWRAP,
//	INSIDE_OVERWRAP,
//	OUTSIDE_OVERWRAP
//} tenum;


// SORT
// ISIERSRE : 이런식으로 하면 될것 같은데....

class Solution {
public:
	vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
		vector<vector<int>> ans;
		// sort need ? 
		// sort(p.begin(), p.end(), [](pair<int, int> l, pair<int, int> r) {
		//	if (l.first == r.first) return l.second > r.second; return l.first < r.first; });

		for (auto it : intervals) {

			// NO_OVERRAP
			if ((it[1] <= toBeRemoved[0]) || (toBeRemoved[1] <= it[0])) {
				ans.push_back(it);
			}

			// SAME
			//else if (it[1] == toBeRemoved[0] && toBeRemoved[1] == it[0]) {
			//	// skip this interval
			//}
					
			// interval is INSIDE_OVERRAP of toBeRemoved
			else if ((toBeRemoved[0] <= it[0] && it[1] <= toBeRemoved[1])) {
				// skip this interval
			}
			// interval is OUTSIDE_OVERRAP or SAME of toBeRemoved
			else if ((it[0] < toBeRemoved[0]) && (toBeRemoved[1] < it[1])) {
				// Add left & right
				vector<int> l = { it[0], toBeRemoved[0] };
				vector<int> r = { toBeRemoved[1], it[1] };
				ans.push_back(l);
				ans.push_back(r);

			}
 			// interval is LEFT_OVERWRAP of toBeRemoved
			else if ((it[0] < toBeRemoved[0]) && it[0] <= toBeRemoved[1]) {
				vector<int> l = { it[0], toBeRemoved[0] };
				ans.push_back(l);
			}

			// RIGHT_OVERRAP
			else if ((toBeRemoved[0] <= it[0]) && (toBeRemoved[1] < it[1])) {
				vector<int> r = {toBeRemoved[1], it[1]};
				ans.push_back(r);

			}
		}
		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	//vector<string> d = { "abcd", "cccc", "abyd", "abab" };
	//vector<string>d = { "ab", "cd", "yz" };

	//vector<vector<int>> intervals = { {0, 2},{3, 4},{5, 7} };
	//vector<int> toBeRemoved = { 1, 6 };

	//vector<vector<int>>  intervals = { {0, 5} };
	//vector<int> toBeRemoved = { 2, 3 };

	vector<vector<int>> intervals = { {-5, -4},{-3, -2},{1, 2},{3, 5},{8, 9} };
	vector<int> toBeRemoved = { -1, 4 };

	vector<vector<int>> ans = sol.removeInterval(intervals, toBeRemoved);

	cout << "ans= ";
	for (auto it : ans) {
		cout << it[0] << "," << it[1] << endl;
	}
	cin >> c;
}
