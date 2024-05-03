//  ¥‰∫√¿Ω....   why?? 
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
	long long numberOfWeeks(vector<int>& milestones) {
		int mx = *max_element(milestones.begin(), milestones.end());
		long long sum = 0;
		for (int i = 0; i < milestones.size(); i++) {
			sum += (long long)milestones[i];
		}
		long long rest = sum - (long long)mx;
		return min({ rest * 2 + 1, sum });
	}
};

class _Solution {
public:
	long long numberOfWeeks(vector<int>& milestones) {
		multiset<int> ms;
		for (auto &it : milestones) {
			if (it == 0) continue;
			ms.insert(it);
		}

		long long ans = 0;
		while(ms.size() >= 2) {
			int l1 = *ms.rbegin();
			ms.erase(ms.find(l1));
			int l2 = *ms.rbegin();
			ms.erase(ms.find(l2));

			l1 -= l2;
			ans += l2 * 2;

			if(l1 != 0) ms.insert(l1);
		}

		if (ms.size() >= 1 && *ms.rbegin() > 0) {
			int add = *ms.rbegin() / 2;
			ans += (add > 1) ? add : 1;
		}

		return ans;
	}
};


int main() {
	char c;
	Solution sol;

	vector<int> milestones = { 5, 7, 5, 7, 9, 7 }; // { 5, 2, 1 };

	cout << sol.numberOfWeeks(milestones);

	cin >> c;
}