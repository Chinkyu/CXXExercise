//  Several exceptin .....
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
	int minimumNumbers(int num, int k) {
		int tn = num % 10;

		if (num == 0) return 0;
		if (num == k) return 1;
		if (tn == k) return 1;
		if (num < k) return -1;

		set<int> s;

		int acc = k;
		for (int i = 2; i < 100; ++i) {
			acc += k;
			if (acc % 10 == tn) {
				if (num >= acc) {
					return i;
				}
				else {
					return -1;
				}
			}
			if (s.find(acc % 10) != s.end()) {
				return -1;
			}
			else {
				s.insert(acc % 10);
			}
		}
		return -1;
	}
};

int main() {
	char c;

	Solution sol;

	cout << sol.minimumNumbers(10, 8);

	cin >> c;

}