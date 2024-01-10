// eash :  need to add for minus value 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	long long smallestNumber(long long num) {
		long long onum = num;
		bool isMinus = (num < 0)? true: false;

		if (isMinus) num = num * -1;

		string s = to_string(num);
		vector<int> cnt(10, 0);

		if (s.size() == 1) return num;

		for (auto &it : s) {
			cnt[it - '0']++;
		}

		int zCount = cnt[0];
		string ansS;
		bool isFirstDigit = false;


		if (isMinus == false) {		// plus valu
			for (int i = 1; i <= 9; ++i) {
				if (isFirstDigit == false && cnt[i] != 0) {
					ansS.push_back(i + '0');
					cnt[i]--;
					for (int j = 0; j < cnt[0]; ++j) ansS.push_back('0');
					isFirstDigit = true;
				}

				for (int j = 0; j < cnt[i]; ++j) ansS.push_back(i + '0');
			}
		}
		else {						// minus value
			for (int i = 9; i >= 0; --i) {
				for (int j = 0; j < cnt[i]; ++j) ansS.push_back(i + '0');
			}
		}

		long long ans = stoll(ansS);
		if (isMinus) ans = ans * -1;

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	cout << sol.smallestNumber(0);

	cin >> c;
}