// easy
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
	string decodeCiphertext(string encodedText, int rows) {
		int l = encodedText.size();

		if (l <= 0) return "";

		int disp = ceil(l / rows) + 1;	// displacement

		string ans;
		for (int i = 0; i < disp; ++i) {
			int idx = i;
			while (idx < l) {
				ans.push_back(encodedText[idx]);
				idx += disp;
			}
		}

		while (ans[ans.size() - 1] == ' ') ans.pop_back();

		return ans;

	}
};

int main() {
	char c;
	Solution sol;

	pair<int, int> p1, p2;

	string encodedText = "ch   ie   pr";
	cout << sol.decodeCiphertext(encodedText, 3);

	cin >> c;
}