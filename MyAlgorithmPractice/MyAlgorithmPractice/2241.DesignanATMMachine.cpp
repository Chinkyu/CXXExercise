//  easy 
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

class ATM {
public:
	vector<long long> money;
	ATM() {
		money = vector<long long>(5, 0);
	}

	void deposit(vector<int> banknotesCount) {
		for (int i = 0; i < banknotesCount.size(); ++i) {
			money[i] += banknotesCount[i];
		}
	}

	vector<int> withdraw(int amount) {
		vector<int> wd(5, 0);
		vector<int> error = { -1 };
		vector<long long> tmoney = money;

		if (amount >= 500 && tmoney[4] > 0) {
			int c500 = amount / 500;
			if (tmoney[4] <= c500) {
				wd[4] = tmoney[4];
			}
			else {
				wd[4] = c500;
			}
			amount -= wd[4] * 500;
			tmoney[4] -= wd[4];
		}

		if (amount >= 200 && tmoney[3] > 0) {
			int c200 = amount / 200;
			if (tmoney[3] <= c200) {
				wd[3] = tmoney[3];
			}
			else {
				wd[3] = c200;
			}
			amount -= wd[3] * 200;
			tmoney[3] -= wd[3];
		}

		if (amount >= 100 && tmoney[2] > 0) {
			int c100 = amount / 100;
			if (tmoney[2] <= c100) {
				wd[2] = tmoney[2];
			}
			else {
				wd[2] = c100;
			}
			amount -= wd[2] * 100;
			tmoney[2] -= wd[2];
		}

		if (amount >= 50 && tmoney[1] > 0) {
			int c50 = amount / 50;
			if (tmoney[1] <= c50) {
				wd[1] = tmoney[1];
			}
			else {
				wd[1] = c50;
			}
			amount -= wd[1] * 50;
			tmoney[1] -= wd[1];
		}

		if (amount % 20 != 0) return error;
		if (amount / 20 > tmoney[0]) return error;
		wd[0] = amount / 20;
		tmoney[0] -= wd[0];

		// success
		for (int i = 0; i < money.size(); ++i) {
			money[i] = tmoney[i];
		}

		return wd;
	}
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */

int main() {
	char c;

	Solution sol;

	vector<vector<int>> circles = { {2, 2, 2}, {3, 4, 1} };

	cout << sol.countLatticePoints(circles);

	cin >> c;

}