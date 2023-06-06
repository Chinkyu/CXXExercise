// 처음짠게 타임아웃
// 리턴으로 누적하면서.. momoization 해서 해결(답 참조)
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
	long long maxPoint = 0;

	long long traverse(vector<vector<int>> &questions, vector<long long> &v, int idx) {
		long long ans = 0;

		if (idx >= questions.size()) {
			return 0;
		}

		if (v[idx] != -1) return v[idx];

		// not select
		long long no = traverse(questions, v, idx + 1);

		// select
		long long yes = questions[idx][0] + traverse(questions, v, idx + questions[idx][1] + 1);

		ans = max(no, yes);

		v[idx] = ans;
		return ans;
	}


	long long mostPoints(vector<vector<int>>& questions) {
		vector<long long> v(questions.size(), -1);

		return traverse(questions, v, 0);
	}
};

int main() {
	char c;

	Solution sol;

	vector<vector<int>> questions = { {3,2}, {4,3}, {4,4}, {2, 5} };

	cout << sol.mostPoints(questions);

	cin >> c;
}