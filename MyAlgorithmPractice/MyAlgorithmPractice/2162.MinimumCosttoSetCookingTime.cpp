// eash :  several exception handling 
#include <iostream>
#include <vector>
#include <unordered_map>
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
	int cost(int startAt, int moveCost, int pushCost, string s) {
		char cur = startAt + '0';
		int cst = 0;

		for (auto &it : s) {
			if (cur != it) {
				cst += moveCost;
				cur = it;
			}
			cst += pushCost;
		}
		return cst;
	}


	int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
		int m = targetSeconds / 60;
		int s = targetSeconds % 60;

		string str = "";
		int tmin = INT_MAX;

		if (m >= 100) {  // m can be only 100;
			m = 99;
			s = s + 60;
		}

		if (m > 0) {
			str = to_string(m);
			//str.append(to_string(s));
			stringstream ss;
			ss << setw(2) << setfill('0') << s;
			str.append(ss.str());

			tmin = min(tmin, cost(startAt, moveCost, pushCost, str));
		}
		else {
			str.append(to_string(s));
			tmin = min(tmin, cost(startAt, moveCost, pushCost, str));
		}

		if(m > 0 && s + 60 < 100) {
			str = "";
			if(m - 1 > 0) str = to_string(m - 1);
			//str.append(to_string(s + 60));
			stringstream ss;
			ss << setw(2) << setfill('0') << s+60;
			str.append(ss.str());
			tmin = min(tmin, cost(startAt, moveCost, pushCost, str));
		}
		
		return tmin;
	}
};

int main() {
	char c;

	Solution sol;

	cout << sol.minCostSetTime(1, 9403, 9492, 6008);
	cin >> c;
}