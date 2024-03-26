//  easy :  
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

class Bank {
public:
	vector<long long> iBalance;
	int l;
	Bank(vector<long long>& balance) {
		iBalance = balance;
		l = iBalance.size();
	}

	bool transfer(int account1, int account2, long long money) {

		if (account1 < 1 || l < account1 ||
			account2 < 1 || l < account2) return false;

		if (iBalance[account1 - 1] < money) return false;

		iBalance[account1 - 1] -= money;
		iBalance[account2 - 1] += money;
		return true;
	}

	bool deposit(int account, long long money) {
		if (account < 1 || l < account) return false;
		iBalance[account - 1] += money;
		return true;
	}

	bool withdraw(int account, long long money) {
		if (account < 1 || l < account) return false;
		if (iBalance[account - 1] < money) return false;

		iBalance[account - 1] -= money;
		return true;
	}
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */


int main() {
	char c;
	Solution sol;

	vector<int> nums = { 3, 1 };

	cout << sol.countMaxOrSubsets(nums);

	cin >> c;
}