//  답봤음.. 바이너리서치
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <iomanip>

using namespace std;

class Solution {
public:
	int n;
	bool good(int x, long long k, vector<int> &arr) {
		long long ct = 0;
		for (int i = 0; i < n; i++) {
			ct += (arr[i] / x);
		}
		return (ct >= k);
	}
	int maximumCandies(vector<int>& arr, long long k) {
		int low = 1;
		int high = 1e9 + 1;
		n = arr.size();
		int ans = 0;

		while (low <= high) {
			int mid = low + (high - low) / 2;

			if (good(mid, k, arr)) {
				ans = mid;
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	string expression = "12+34"; // "247+38"; // "9999+9999"; 
	cout << sol.minimizeResult(expression);


	cin >> c;

}