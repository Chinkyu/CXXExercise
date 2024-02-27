// tricky in debugging : slinding window : tricky in ==
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
	vector<int> goodDaysToRobBank(vector<int>& security, int time) {
		int l = security.size();
		vector<int> acc(l, 0);

		vector<int> ans;

		if (l < time * 2 + 1) return ans;

		for (int i = 1; i < l; ++i) {
			if (security[i - 1] < security[i]) {
				acc[i] = 1;
			}
			else if (security[i - 1] > security[i]) {
				acc[i] = -1;
			}
			else {  // same
				acc[i] = 0;
			}
		}

		int leftinc = 0, rightdec = 0;
		for (int i = 1; i <= time; ++i) if (acc[i] == 1) leftinc++;
		for (int i = time + 1; i <= time + time; ++i) if (acc[i] == -1) rightdec++;

		if (leftinc == 0 && rightdec == 0) ans.push_back(time);

		for (int i = time + 1; i < l - time; ++i) {
			if (time != 0 && acc[i - time] == 1) leftinc--;
			if (time != 0 && acc[i] == 1) leftinc++;
			
			if (time != 0 && acc[i] == -1) rightdec--;
			if (time != 0 && acc[i + time] == -1) rightdec++;

			if (leftinc == 0 && rightdec == 0) ans.push_back(i);
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> security = { 1,2,5,4,1,0,2,4,5,3,1,2,4,3,2,4,8 }; //  { 4, 3, 2, 1 }; // { 1, 1, 1, 1, 1 }; // //{ 1,2,3,4,5,6 }; //  // { 5, 3, 3, 3, 5, 6, 2 };

	vector<int> ans = sol.goodDaysToRobBank(security, 2);

	for (auto it : ans) {
		cout << it << " ";
	}

	cin >> c;
}