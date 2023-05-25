// 타임아웃나서 답 봤음...내용은 안봄.....  왜??몰라... 

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

// 답.. curr_max 가 포인트 인것 같은데.... 
class Solution {
public:
	bool canReach(string s, int minJump, int maxJump) {
		int n = s.length();
		if (s[n - 1] != '0')
			return false;

		int i = 0;
		queue<int> q;
		q.push(0);
		int curr_max = 0;

		while (!q.empty()) {
			i = q.front();
			q.pop();
			if (i == n - 1)
				return true;

			for (int j = max(i + minJump, curr_max); j <= min(i + maxJump, n - 1); j++) {
				if (s[j] == '0')   q.push(j);
			}
			curr_max = min(i + maxJump + 1, n);
		}
		return false;
	}
};

// timout 
class _Solution {
public:
	bool canReach(string s, int minJump, int maxJump) {
		int l = s.size();
		set<int> q;

		q.insert(0);
		do {
			set<int> r;
			for (auto it : q) {
				for (int i = it + minJump; i <= it + maxJump && i < l; ++i) {
					if (i >= l) break;
					if (s[i] == '0') {
						r.insert(i);
						if (i == l - 1) return true;
					}
				}
			}
			q = r;
		} while (q.size() != 0);

		return false;
	}
};

int main() {
	char c;
	Solution sol;

	string s = "01101110"; //  "011010";
	cout << sol.canReach(s, 2, 3);

	cin >> c;
}