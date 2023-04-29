//  내용이 이상해서 그냥 답봄... 
  
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	bool verifyPreorder(vector<int>& preorder) {
		stack<int> stk;
		int lower_bound = INT_MIN;
		for (int i = 0; i < preorder.size(); i++) {
			if (stk.empty() || preorder[i] < preorder[i - 1]) {
				if (preorder[i] <= lower_bound) return false;
				stk.push(preorder[i]);
			}
			else {
				while (!stk.empty() && stk.top() < preorder[i]) {
					lower_bound = stk.top();
					stk.pop();
				}
				stk.push(preorder[i]);
			}
		}

		return true;
	}
};

class _Solution {
public:
	int result = true;
	void traverse(stack<int> &st, vector<int> &preorder, int &idx) {
		if (result == false) return;

		int father = preorder[idx++];

		if (idx >= preorder.size()) return;
		//st.push(father);

		if (preorder[idx] < father) { // left son
			traverse(st, preorder, idx);
			if (idx >= preorder.size()) { result = false; return; }
			if (preorder[idx] < father) { result = false; return; }
			traverse(st, preorder, idx);
		}

		return;
	}


	bool verifyPreorder(vector<int>& preorder) {
		stack<int> st;
		int idx = 0;
		result = true;

		traverse(st, preorder, idx);
		if (idx == preorder.size()) return result;
		return result;
	}
};


int main() {
	char c;

	Solution sol;
	vector<int> preorder = { 2, 1 }; //  { 5, 2, 6, 1, 3 };

	cout << sol.verifyPreorder(preorder);
	//	cout << sol.countHighestScoreNodes(parents) << endl;
	//	cout << "test : " << ans << endl;

	cin >> c;
}