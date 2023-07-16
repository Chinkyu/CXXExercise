//	합을 나눈 나머지 가지고 따지면 됨.. 
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
#include <cmath>

using namespace std;

class Solution {
public:
	int chalkReplacer(vector<int>& chalk, int k) {
		int n = chalk.size();
		long long sum = 0;
		for (auto it : chalk) {
			sum += it;
		}

		int remain = k % sum;

		for (int i = 0; i < n; ++i) {
			if (remain < chalk[i]) {
				return i;
			}
			
			remain -= chalk[i];
		}
		return -1;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> chalk = { 5, 1, 5 };
	cout << sol.chalkReplacer(chalk, 22);

	cin >> c;
}
