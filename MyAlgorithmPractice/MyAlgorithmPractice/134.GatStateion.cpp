#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		vector<int> rem;
		
		for (int i = 0; i < n; ++i) {
			rem.push_back(gas[i] - cost[i]);
		}

		if (n == 1) {
			if (rem[0] >= 0) {
				return 0;
			}
			else {
				return -1;
			}
		}

		for (int i = 0; i < n; ++i) {
			if (rem[i] <= 0) continue;
			int idx = i;
			int sum = 0;
			for (int j = 0; j < n; ++j) {
				sum += rem[idx];
				if (sum < 0) break;
				if (j == n - 1 && sum >= 0) return i;
				idx++;
				idx %= n;
			}
		}
		return -1;
	}
};

int main() {
	Solution sol;
	char c;
//	vector<int> gas = { 1, 2, 3, 4, 5 };
//	vector<int> cost = { 3, 4, 5, 1, 2 };
	vector<int> gas = {2};
	vector<int> cost = {2};


	cout << sol.canCompleteCircuit(gas, cost);

	cin >> c;
}