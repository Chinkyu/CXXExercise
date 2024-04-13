// easy 
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
	vector<int> findOriginalArray(vector<int>& changed) {
		int l = changed.size();
		vector<int> empty, ans;
		map<int, int> m;

		if (l % 2 != 0) return empty;

		for (auto &it : changed) m[it]++;
		
		while (m.size() > 0) {
			int oVal = m.begin()->first;
			if (m.find(oVal * 2) != m.end()) {
				ans.push_back(oVal);
				m[oVal]--;
				m[oVal * 2]--;
				if (m[oVal] < 0) return empty;
				if (m[oVal * 2] < 0) return empty;
				if (m[oVal] == 0) m.erase(oVal);
				if (m[oVal * 2] == 0) m.erase(oVal * 2);
			}
			else {
				return empty;
			}
		}

		//if (m.size() != 0) return empty;
		return ans;

	}
};

int main() {
	char c;
	Solution sol;

	vector<int> changed = { 0, 0, 0, 0 }; // { 6, 3, 0, 1 }; //{ 1,3,4,2,6,8 }; // { 6, 3, 0, 1 };

	vector<int> ans = sol.findOriginalArray(changed);

	for (auto &it : ans) {
		cout << it << " ";
	}

	cin >> c;
}