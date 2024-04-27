// 답봤음 : stack  으로 그냥 풀리네..
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


class Solution {
public:
	int minSwaps(string s)
	{
		stack<char>st;
		int count = 0;
		for (char c : s)
		{
			if (c == '[') st.push(c);
			else
			{
				if (st.empty()) count++;
				else st.pop();
			}
		}

		int ans = count / 2;
		if (count % 2) ans++;
		return ans;
	}
};

class _Solution {
public:
	int minSwaps(string s) {
		vector<int> v;

		int i = 0;
		int maxMin = 0;
		for (auto &it : s) {
			i = (it == ']') ? --i : ++i;
			v.push_back(i);
			maxMin = min(maxMin, i);
		}

		return abs(maxMin + 1);
	}
};

int main() {
	char c;
	Solution sol;

	string s = "]]][[["; // "][][][";

	cout << sol.minSwaps(s);

	cin >> c;
}