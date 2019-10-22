#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int bulbSwitch(int n) {
		vector<bool> bulb(n + 1, true);

		if (n <= 0) return 0;
		int ans = 1;
		int cnt = 3;
		int j = 0;
		for (int i = 1; i <= n; ++i) {
			if (j >= cnt) {
				j = 0;
				cnt += 2;
				ans++;
			}
			j++;
		}
		return ans;
	}

	int _bulbSwitch(int n) {
		vector<bool> bulb(n+1, true);

		for (int i = 2; i <= n; ++i) {
			int j = 1;
			while (i * j <= n) {
				bulb[i * j] = (bulb[i * j] == true) ? false : true;
				j++;
			}
		}

		int count = 0;
		for (int i = 1; i <= n; ++i) {
			if (bulb[i] == true) count++;
		}
		return count;
	}
};

int main() {
	Solution sol;
	char c;

	for (int i = 1; i < 50; i++) {
		cout << i << " " << sol.bulbSwitch(i) << endl;
	}

	cin >> c;
}