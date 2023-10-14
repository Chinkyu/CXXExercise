// break/continue 헛갈려서  좀 오래걸림. 
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

class Solution_v1 {
public:
	int visibleMountains(vector<vector<int>>& peaks) {

		vector<vector<int>> updown;
		int l = peaks.size();

		for (int i = 0; i < l; ++i) {
			updown.push_back({ peaks[i][0] - peaks[i][1], peaks[i][0] + peaks[i][1], 1 });  // last 1(valid)
		}

		sort(updown.begin(), updown.end(), [](vector<int> &l, vector<int> &r) {
			if (l[0] == r[0]) {
				return r[1] > l[1];
			}
			return l[0] < r[0];
		});

		int count = 0;

		// remove inclusion
		for (int i = 0; i < l; ++i) {
			for (int j = i + 1; j < l; ++j) {
				// XXX : if same with i
				if (updown[i][0] == updown[j][0] && updown[i][1] == updown[i][1]) {
					updown[i][2] = 0;
					updown[i][2] = 0;
				}

				//
				if (updown[j][1] <= updown[i][1]) {
					updown[j][2] = 0;
				}
				else {
					continue;
				}
			}
		}

		// count
		for (int i = 0; i < l; ++i) {
			if (updown[i][2] == 1) count++;
		}

		return count;
	}
};

// timeout as well
class Solution_v2 {
public:
	int visibleMountains(vector<vector<int>>& peaks) {

		vector<vector<int>> updown;
		int l = peaks.size();

		for (int i = 0; i < l; ++i) {
			updown.push_back({ peaks[i][0] - peaks[i][1], peaks[i][0] + peaks[i][1], 1 });  // last 1(valid)
		}

		sort(updown.begin(), updown.end(), [](vector<int> &l, vector<int> &r) {
			if (l[0] == r[0]) {
				return r[1] > l[1];
			}
			return l[0] < r[0];
		});

		int count = 0;

		// remove inclusion
		for (int i = 0; i < l; ++i) {
			if (updown[i][2] == 0) continue;
			for (int j = i + 1; j < l; ++j) {
				// XXX : if same with i
				if (updown[i][0] == updown[j][0] && updown[i][1] == updown[i][1]) {
					updown[i][2] = 0;
					updown[i][2] = 0;
				}

				//
				if (updown[j][1] <= updown[i][1]) {
					updown[j][2] = 0;
				}
				else {
					continue;
				}
			}
			if (updown[i][2] == 1) count++;
		}

		// count
		//for (int i = 0; i < l; ++i) {
		//	if (updown[i][2] == 1) count++;
		//}

		return count;
	}
};


// adding preprocessing  only max 
class Solution {
public:
	int visibleMountains(vector<vector<int>>& peaks) {

		vector<vector<int>> updown;
		int l = peaks.size();

		for (int i = 0; i < l; ++i) {
			updown.push_back({ peaks[i][0] - peaks[i][1], peaks[i][0] + peaks[i][1], 1 });  // last 1(valid)
		}

		sort(updown.begin(), updown.end(), [](vector<int> &l, vector<int> &r) {
			if (l[0] == r[0]) {
				return r[1] > l[1];
			}
			return l[0] < r[0];
		});

		int count = 0;

		// remove inclusion
		for (int i = 0; i < l; ++i) {
			if (updown[i][2] == 0) continue;
			for (int j = i + 1; j < l; ++j) {
				// XXX : if same with i
				if (updown[i][0] == updown[j][0] && updown[i][1] == updown[i][1]) {
					updown[i][2] = 0;
					updown[i][2] = 0;
				}

				//
				if (updown[j][1] <= updown[i][1]) {
					updown[j][2] = 0;
				}
				else {
					break;
				}
			}
			if (updown[i][2] == 1) count++;
		}

		// count
		//for (int i = 0; i < l; ++i) {
		//	if (updown[i][2] == 1) count++;
		//}

		return count;
	}
};


int main() {
	char c;

	Solution sol;

	vector<vector<int>> peaks; // = { {2,2}, {6, 3}, {5, 4} };

	for (int i = 0; i < 99999; ++i) {
		peaks.push_back({ i, 1 });
	}


	cout << sol.visibleMountains(peaks);

	cin >> c;

}