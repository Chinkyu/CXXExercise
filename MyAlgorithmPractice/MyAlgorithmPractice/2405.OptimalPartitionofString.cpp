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
	int partitionString(string s) {
		set<char> st;

		int num = 0;
		for (auto it : s) {
			if (st.find(it) != st.end()) {
				st.clear();
				st.insert(it);
				num++;
				continue;
			}
			else {
				st.insert(it);
			}
		}

		if (st.size() > 0) num++;
		return num;
	}

};

int main() {
	char c;

	Solution sol;

	string s = "abacaba";
	cout << sol.partitionString(s);

	cin >> c;
}