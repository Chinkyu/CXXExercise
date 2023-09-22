//  easy
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
	bool isStrictlyPalindromic(int n) {

		for (int base = 2; base <= n - 2; ++base) {
			vector<int> v;
			int tn = n;

			while (tn != 0) {
				v.push_back(tn % base);
				tn = tn / base;
			}

			// check palindrom 
			int l = v.size();
			for (int i = 0; i < l / 2; ++i) {
				if(v[i] != v[l - i - 1])return false;
			}
		}
		return true;
	}
};



int main() {
	char c;

	Solution sol;

	cout << sol.isStrictlyPalindromic(9);

	cin >> c;
}