// 답봤음 :   어떻게 바이너리 써치????  
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
	bool isPossible(vector<int>& quantities, int mid, int n) {
		int stores = 0;
		for (int i = 0; i < quantities.size(); i++) {
			if (quantities[i] % mid != 0) {
				stores += quantities[i] / mid;
				stores++;
			}
			else {
				stores += quantities[i] / mid;
			}

			if (stores > n) {
				return false;
			}
		}

		return stores <= n;
	}


	int minimizedMaximum(int n, vector<int>& quantities) {
		int start = 1;
		int end = *max_element(quantities.begin(), quantities.end());

		int ans = -1;
		while (start <= end) {
			int mid = start + (end - start) / 2;
			if (isPossible(quantities, mid, n)) {
				ans = mid;
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}

		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> quantities = { 15, 10, 10 };

	cout << sol.minimizedMaximum(7, quantities);

	cin >> c;
}