// �� ���� Ǯ����... �̰��� �����ϰ� recursive�ϸ鼭 ��� �� ���ٴ°��� �����ϱ� ����.. 
// ��°�� �ƴϵ��� s1 �� �ְų� s2�� �ְų�.. �ʳְų� ��� �� ���鼭.. 
// ������ ������ Ȯ�� �ϴ� �����... 

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