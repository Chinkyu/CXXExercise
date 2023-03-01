// vector 로 하면 중복 되는게 있는데.. set 으로 한 뒤에 vector로 카피하면서 쉽게 해결 됨.. 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <map>

using namespace std;

class Solution {
public:

	set<int> sans;

	void iterate(int v, int n, int idx, int k) {
		if (idx == n) {
			sans.insert(v);
			return;
		}

		int c_num = v % 10;

		if (c_num - k >= 0) {
			int tv = v;
			tv *= 10;
			tv += c_num - k;
			iterate(tv, n, idx + 1, k);
		}

		if (c_num + k < 10) {
			int tv = v;
			tv *= 10;
			tv += c_num + k;
			iterate(tv, n, idx + 1, k);
		}
	}

	vector<int> numsSameConsecDiff(int n, int k) {
		sans.clear();
		vector<int> ans;

		for (int i = 1; i < 10; ++i) {
			iterate(i, n, 1, k);
		}

		for (auto it : sans) ans.push_back(it);

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> ans = sol.numsSameConsecDiff(2, 1);

	for (auto it : ans) {
		cout << " " << it;
	}
	cout << endl;

	cin >> c;
}