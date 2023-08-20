// long long  과  %  연산자가 관건이었음. 
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
	unordered_map<long long, int> memo;
	long long traverse(int low, int high, int zero, int one, long long len) {
		long long sum = 0;

		if (len > high) return 0;

		if (memo.find(len) != memo.end()) return memo[len];


		if (zero + len <= high) {
			if (low <= zero + len)	sum++;
			sum += traverse(low, high, zero, one, len + (long long)zero);
		}

		if (one + len <= high) {
			if (low <= one + len) sum++;
			sum += traverse(low, high, zero, one, len + (long long)one);
		}

		memo[len] = sum % 1000000007;
		return memo[len];
	}

	int countGoodStrings(int low, int high, int zero, int one) {
		return traverse(low, high, zero, one, 0);
	}

};

int main() {
	char c;

	Solution sol;
	
	cout << sol.countGoodStrings(200, 200, 10, 1);

	cin >> c;
}