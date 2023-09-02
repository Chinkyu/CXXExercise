// 답봤고.. 대략 이해.... 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
//  답 봤고.. right min  이 관견
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	string robotWithString(string s) {
		int n = s.size();
		string temp = s;
		vector<char> rightmin(n, 'z');
		rightmin[n - 1] = s[n - 1];
		for (int i = n - 2; i >= 0; i--)
		{
			rightmin[i] = min(s[i], rightmin[i + 1]);
		}

		string t = "", p = "";
		for (int i = 0; i < n; i++)
		{
			while (t.size() && t.back() <= s[i] && t.back() <= rightmin[i])
			{
				p += t.back();
				t.pop_back();
			}
			t += s[i];
		}
		while (t.size()) {
			p += t.back();
			t.pop_back();
		}
		return p;
	}
};

int main() {
	char c;

	Solution sol;
	vector<int> nums = { 1, 13, 10, 12, 31 };

	cout << sol.countDistinctIntegers(nums);

	cin >> c;
}