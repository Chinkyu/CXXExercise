// OK : tricky debugging 
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

class LockingTree {
public:
	unordered_map<int, vector<int>> m;
	vector<int> parentv;
	vector<int> lockv;

	LockingTree(vector<int>& parent) {
		int l = parent.size();
		parentv = parent;
		lockv = vector<int>(l, 0);  // user 0 : unlock 
		for (int i = 1; i < l; ++i) {
			m[parent[i]].push_back(i);
		}
	}

	bool lock(int num, int user) {
		if (lockv[num] == 0) {
			lockv[num] = user;
			return true;
		}
		return false;
	}

	bool unlock(int num, int user) {
		if (lockv[num] == user) {
			lockv[num] = 0;
			return true;
		}
		return false;
	}

	bool upgrade(int num, int user) {
		// check all unlock
		if (lockv[num] != 0) return false;

		int p = num;
		while (p != -1) {
			if (lockv[p] != 0) return false;
			p = parentv[p];
		}

		bool isChildLocked = false;
		queue<int> q;
		q.push(num);
		// check at lease one locked child
		while (!q.empty()) {
			int n = q.front();
			q.pop();

			if (lockv[n] != 0) {       // is locked -> unlock
				isChildLocked = true;
				lockv[n] = 0;
			}
			for (auto &it : m[n]) q.push(it);
		}

		if (isChildLocked == false) return false;

		lockv[num] = user;
		return true;
	}
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */

int main() {
	char c;
	Solution sol;

	vector<vector<int>> properties = { {7, 7}, {1, 2}, {9, 7}, {7, 3}, {3, 10}, {9, 8}, {8, 10}, {4, 3}, {1, 5}, {1, 5} };
	//{ {1, 5}, {10, 4}, {4, 3} };

	cout << sol.numberOfWeakCharacters(properties);

	cin >> c;
}