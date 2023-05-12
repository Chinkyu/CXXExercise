//  esay

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
	string intToRoman(int num) {
		map<int, string> m = {
		{1, "I"},
		{2, "II"},
		{3, "III"},
		{4, "IV"},
		{5, "V"},
		{6, "VI"},
		{7, "VII"},
		{8, "VIII"},
		{9, "IX"},
		{10, "X"},
		{20, "XX"},
		{30, "XXX"},
		{40, "XL"},
		{50, "L"},
		{60, "LX"},
		{70, "LXX"},
		{80, "LXXX"},
		{90, "XC"},
		{100, "C"},
		{200, "CC"},
		{300, "CCC"},
		{400, "CD"},
		{500, "D"},
		{600, "DC"},
		{700, "DCC"},
		{800, "DCCC"},
		{900, "CM"},
		{1000, "M"},
		{2000, "MM"},
		{3000, "MMM"},
		{4000, "MMMM"},
		};

		string ans = "";

		int th = num - (num % 1000);
		int hu = num - th - (num % 100);
		int te = num - th - hu - (num % 10);
		int nu = num % 10;

		ans += m[th];
		ans += m[hu];
		ans += m[te];
		ans += m[nu];

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	cout << sol.intToRoman(58);

	cin >> c;
}