// ¥‰∫√¿Ω
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

class Solution {
public:
	long long maximumSubsequenceCount(string text, string pattern) {
		long long res = 0, cnt1 = 0, cnt2 = 0;
		for (char& c : text) {
			if (c == pattern[1])
				res += cnt1, cnt2++;
			if (c == pattern[0])
				cnt1++;
		}
		return res + max(cnt1, cnt2);
	}
};

int main() {
	char c;

	Solution sol;


	vector<int> nums = { 5, 19, 8, 1 };
	cout << sol.halveArray(nums);

	cin >> c;

}