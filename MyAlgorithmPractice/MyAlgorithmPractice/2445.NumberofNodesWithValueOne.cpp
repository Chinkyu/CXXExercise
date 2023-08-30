// 답봤는데 짝수 Request 무시 하는것 추가해서 timeout pass 
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


// timeout... 
class Solution1 {
public:
	void flip(int n, vector<int> & node, int r) {
		//int l = node.size();
		queue<int> q;

		q.push(r);
		while (!q.empty()) {
			int p = q.front();
			q.pop();
			if(p <= n) node[p] = (node[p] == 0) ? 1 : 0;
			int lc = p * 2, rc = p * 2 + 1;
			if (lc <= n) q.push(lc);
			if (rc <= n) q.push(rc);
		}
	}

	int numberOfNodes(int n, vector<int>& queries) {
		vector<int> node(n + 1, 0);

		for (auto it : queries) {
			flip(n, node, it);
		}

		int ans = 0;
		for (int i = 1; i <= n; ++i) if (node[i] == 1) ans++;

		return ans;
	}
};

class Solution {
public:
	void flip(int n, vector<int> & node, int r) {
		//int l = node.size();
		queue<int> q;

		q.push(r);
		while (!q.empty()) {
			int p = q.front();
			q.pop();
			if (p <= n) node[p] = (node[p] == 0) ? 1 : 0;
			int lc = p * 2, rc = p * 2 + 1;
			if (lc <= n) q.push(lc);
			if (rc <= n) q.push(rc);
		}
	}

	int numberOfNodes(int n, vector<int>& queries) {
		vector<int> node(n + 1, 0);
		unordered_map<int, int> mq;

		for (auto it : queries) {
			mq[it] = (mq[it] == 1) ? 0 : 1;
		}


		for (auto it : mq) {
			if(it.second == 1) flip(n, node, it.first);
		}

		int ans = 0;
		for (int i = 1; i <= n; ++i) if (node[i] == 1) ans++;

		return ans;
	}
};


int main() {
	char c;

	Solution sol;

	vector<int> queries = { 1, 2, 5 };
	cout << sol.numberOfNodes(5, queries);

	cin >> c;
}