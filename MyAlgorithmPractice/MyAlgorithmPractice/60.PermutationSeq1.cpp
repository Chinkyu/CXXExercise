#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int> pact(n - 1, 1);
		vector<int> cnt(n - 1, 0);
		string ans;

		for (int i = 1; i < n -1; ++i) {
			pact[i] = pact[i - 1] * (i + 1);
		}

		int val = k-1;
		for (int i = n - 2; i >= 0; --i) {
			cnt[i] = val / pact[i];
			val = val % pact[i];
		}

		vector<bool> accur(n+1, false);
		int idx = 0;
		for (int i = n - 2; i >= 0; --i) {
			idx = 0;
			for (int j = 0; j <= cnt[i]; ++j) {
				do {
					idx++;
				} while (accur[idx] == true);
			}
			accur[idx] = true;
			ans.push_back(idx + '0');

		}

		// last digit
		for (int i = 1; i < n + 1; ++i) {
			if (accur[i] == false) {
				ans.push_back(i + '0');
				break;
			}
		}

		return ans;
	}
};

int main() {
	Solution sol;
	char c;

	cout << sol.getPermutation(4, 9).c_str();

	cin >> c;
}