// 답 봤음... 큐 가지고 간단하게.. 풀리는데.... 참.... 생각 하기 쉽지 않아 보임.. 
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

/*
Greedy should work. We start from either side, and trying to pair it or non-it with the closest reachable oposite persion. It's easy to prove that this strategy maximizes the number of matches.

[... this could be more interesting if people are standing in a circle ...]

We can simulate this logic with a queue. The first solution uses two queues, with the hope it's easier to understand. The next one is practically the same, but with a single queue. The last solution uses two pointers to navigate through the team.

*/

//  이렇게 간단하게 풀린다는게.. 신기 할 따름이다.... 
class Solution {
public:
	int catchMaximumAmountofPeople(vector<int>& team, int dist) {
		queue<int> it, nit;
		int res = 0;
		for (int i = 0; i < team.size(); ++i) {
			if (team[i])
				it.push(i);
			else
				nit.push(i);
			while (!it.empty() && it.front() < i - dist)
				it.pop();
			while (!nit.empty() && nit.front() < i - dist)
				nit.pop();
			if (!it.empty() && !nit.empty()) {
				++res;
				it.pop();
				nit.pop();
			}
		}
		return res + min(it.size(), nit.size());
	}
};

//   dist  가 크면 써치 스페이스가 커서  timeout ㄴㅁ 
class _Solution {
public:
	int catchMaximumAmountofPeople(vector<int>& team, int dist) {
		int l = team.size();
		int ans = 0;

		//:: make catchable map
		for (int i = 0; i < l; ++i) {
			if (team[i] == 1) {
				int st = ((i - dist) < 0) ? 0 : (i - dist);
				int ed = (l - 1 < (dist + i)) ? l - 1: dist + i;
				for (int j = st; j <= ed; j++) {
					if (team[j] == 0) {
						team[j] = 11;
					}
					else if (team[j] > 10) {
						team[j]++;
					}
				}
			}
		}

		// Catch to -1   with mininum scope
		for (int i = 0; i < l; ++i) {
			if (team[i] == 1) {
				int st = ((i - dist) < 0) ? 0 : (i - dist);
				int ed = (l - 1 < (dist + i)) ? l - 1 : dist + i;
				int min_val = INT_MAX, min_idx = -1;
				for (int j = st; j <= ed; j++) {
					if (team[j] > 10 && team[j] < min_val) {
						min_val = team[j];
						min_idx = j;
					}
				}
				if (min_idx != -1) {
					team[min_idx] = -1;
					ans++;
				}
			}
		}
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> team = { 0, 1, 0, 1, 0 };

	cout << sol.catchMaximumAmountofPeople(team, 3);

	cin >> c;
}