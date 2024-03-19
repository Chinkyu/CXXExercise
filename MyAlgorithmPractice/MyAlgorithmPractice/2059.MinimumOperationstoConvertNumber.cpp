// just see to reduce timeout : don't visit again visited node 
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
	int minimumOperations(vector<int>& nums, int start, int goal) {

		int ans = 0;
		set<int> q;

		q.insert(start);

		unordered_map<int, bool> visit;
		visit[start] = true;

		do {
			set<int> qt;
			for (auto &it : q) {
				for (auto &jt : nums) {
					int res = it + jt;
					if (res == goal) return ++ans;
					if (0 <= res && res <= 1000 && visit[res] == false) {
						qt.insert(res);
						visit[res] = true;
					}

					res = it - jt;
					if (res == goal) return ++ans;
					if (0 <= res && res <= 1000 && visit[res] == false) {
						qt.insert(res);
						visit[res] = true;
					}
					
					res = it ^ jt;
					if (res == goal) return ++ans;
					if (0 <= res && res <= 1000 && visit[res] == false) {
						qt.insert(res);
						visit[res] = true;
					}
				}
			}

			if (q == qt) break;  // there is no progress 
			q = qt;
			ans++;
		} while (!q.empty());

		return -1;
	}
};

int main() {
	char c;
	Solution sol;

	//vector<int> nums = { 2, 4, 12 };
	//vector<int> nums = { 2, 8, 16 };
	vector<int> nums = { -5};

	cout << sol.minimumOperations(nums, 3, 0);

	cin >> c;
}