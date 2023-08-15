// easy - 디버깅 하는데..   마지막 시간 추가 하는것 추가 확인 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	int bestClosingTime(string customers) {
		int l = customers.size();
		vector<int> p(l+1, 0);
		int min_idx = 0;

		// Penalty for idx 0
		for (int i = 0; i < l; ++i) {
			if (customers[i] == 'Y') p[0]++;
		}
		min_idx = 0;

		// As moving 
		// 'Y' : Penalty -1
		// 'N' : Penalty + 1
		for (int i = 1; i <= l; ++i) {
			p[i] = p[i - 1];
			if (customers[i-1] == 'Y') {  // 'Y'   -1
				p[i]--;
			}
			else {						// 'N' + 1
				p[i]++;
			}

			min_idx = (p[i] < p[min_idx]) ? i : min_idx;
		}

		return min_idx;
	}
};

int main() {
	char c;

	Solution sol;
	string customers =  "YYYY"; // "NNNNN"; // "YYNY";
	cout << sol.bestClosingTime(customers);

	cin >> c;
}