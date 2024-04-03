//  easy with  ³ª¶ó½Ã... : 
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

// timeout 
class _Solution {
public:

	vector<int> ans;
	bool traverse(vector<int> &v, int idx, int sum, int n, int target) {

		if (idx >= n) {
			if (sum == target) {
				ans = v;
				return true;
			}
			return false;
		}
			   
		for (int i = 1; i <= 6; ++i) {
			v[idx] = i;
			if (traverse(v, idx + 1, sum + i, n, target)) return true;
		}

		return false;
	}

	vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
		int rtotal = 0;
		int ktotal = 0;
		vector<int> empty, v(n, 0);
		ans = vector<int>(n, 0);

		for (auto &it : rolls) ktotal += it;

		rtotal = mean * (rolls.size() + n) - ktotal;

		// need to find combination with n number can make rtotal;
		if (rtotal > n * 6) return empty;
		if (rtotal < n) return empty;

		if (traverse(v, 0, 0, n, rtotal) == false) return empty;

		return ans;
	}
};

class Solution {
public:


	vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
		int rtotal = 0;
		int ktotal = 0;
		vector<int> empty, v(n, 0), ans(n, 0);
		ans = vector<int>(n, 0);

		for (auto &it : rolls) ktotal += it;

		rtotal = mean * (rolls.size() + n) - ktotal;

		// need to find combination with n number can make rtotal;
		if (rtotal > n * 6) return empty;
		if (rtotal < n) return empty;

		int remain = rtotal;
		for (int i = 0; i < n - 1; ++i) {
			ans[i] = 1;
			remain--;
		}
		ans[n - 1] = remain;

		for (int i = n - 1; i > 0; --i) {
			if (ans[i] <= 6) break;
			ans[i - 1] += ans[i] - 6;
			ans[i] = 6;

		}

		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> rolls = { 3, 2, 4, 3 };

	vector<int> ans = sol.missingRolls(rolls, 4, 2);
	
	for (auto &it : ans) {
		cout << it << " ";
	}

	cin >> c;
}