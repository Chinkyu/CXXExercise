// 답 보고 풀었음... 이것을 무식하게 recursive하면서 모두 해 본다는것을 생각하기 힘듬.. 
// 어째뜬 아니디어는 s1 에 넣거나 s2에 넣거나.. 않넣거나 모두 해 보면서.. 
// 끝까지 가서는 확인 하는 방법임... 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <map>

using namespace std;

class Solution {
public:

	bool isPalandrom(string& s) {
		int l = s.size();

		for (int i = 0; i < l / 2; ++i) {
			if (s[i] != s[l - i - 1]) return false;
		}
		return true;
	}

	int ans = 0;

	void traverse(string &s, int idx, string &s1, string &s2) {
		if (idx >= s.size()) {
			if (isPalandrom(s1) && isPalandrom(s2)) {
				ans = max(ans, (int)(s1.size() * s2.size()));
			}
			return;
		}

		// add into s1
		s1.push_back(s[idx]);
		traverse(s, idx + 1, s1, s2);
		s1.pop_back();

		// add into s2
		s2.push_back(s[idx]);
		traverse(s, idx + 1, s1, s2);
		s2.pop_back();

		// no adding 
		traverse(s, idx + 1, s1, s2);
	}

	int maxProduct(string s) {
		string s1 = "", s2 = "";
		ans = 0;
		traverse(s, 0, s1, s2);
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	string s = "leetcodecom";

//	string t = "ete";
//	if (true == sol.isPalandrom(t)) cout << "true" << endl;

	cout << sol.maxProduct(s);

	//cout << sol.minimumSwap(s1, s2);

	cin >> c;
}