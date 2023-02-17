// 무식하게 짰는데..  Accept 되네... 이상하네... 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
	int kthFactor(int n, int k) {
		vector<int> l;

		for (int i = 1; i <= n; ++i) {
			if (n % i == 0) l.push_back(i);

			if (l.size() == k) return l[k - 1];
		}

		return -1;
	}
};

int main() {
	char c;

	Solution sol;

	cout << sol.kthFactor(7, 2) << endl;
	//	cout << "test : " << ans << endl;

	cin >> c;
}