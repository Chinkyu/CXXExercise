//	뒤에서 앞으로  가면서...    뒤것을 앞으로 옮기고 앞에 추가 하면  됨.... 
//  패턴을 확인해서  품. 
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
#include <cmath>

using namespace std;

class Solution {
public:
	vector<int> deckRevealedIncreasing(vector<int>& deck) {
		vector<int> ans;
		deque<int> dq;
		int n = deck.size();
		sort(deck.begin(), deck.end());

		dq.push_back(deck[n - 1]);
		for (int i = n - 2; i >= 0; --i) {
			int t = dq.back();
			dq.pop_back();
			dq.push_front(t);
			dq.push_front(deck[i]);
		}

		for (auto it : dq) {
			ans.push_back(it);
		}
		return ans;
	}
};


int main() {
	char c;

	Solution sol;
	vector<int> deck = { 17, 13, 11, 2, 3, 5, 7 };

	vector<int> ans = sol.deckRevealedIncreasing(deck);

	for (auto it : ans) {
		cout << it << " ";
	}

	cin >> c;
}
