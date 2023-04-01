// 잘 모르겠다... 나준에 보자.. !!! 
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
#define ll long long
#define MOD 1000000007
	int numFactoredBinaryTrees(vector<int>& arr) {
		ll ans = 0;
		unordered_map<ll, ll> up;
		sort(arr.begin(), arr.end());
		for (int i = 0; i < arr.size(); i++) {
			ll currentans = 1;
			for (int j = 0; j < i; j++)
			{
				if (arr[i] % arr[j]) continue;
				int ans1 = arr[i] / arr[j];
				int ans2 = arr[j];
				currentans = (currentans + up[ans1] * up[ans2] % MOD) % MOD;

			}
			up[arr[i]] = currentans;
			ans = ans + currentans;

		}
		return ans % MOD;
	}

};


class _Solution {
public:
	map<int, list<pair<int, int>>> tree;
	int max_d = 0;
	int get_b_num(int r, int d, vector<int> &child_num) {

		if (tree.find(r) == tree.end()) return 1;

		if (max_d < d) max_d = d;
		child_num[d] += tree[r].size();
		for (auto it : tree[r]) {
			//if (tree.find(it.first) == tree.end() && tree.find(it.second) == tree.end()) {
			//	d++;
			//	continue;
			//}
			if(tree.find(it.first) != tree.end()) {
				d += get_b_num(it.first, d + 1, child_num);
			}
			if (tree.find(it.second) != tree.end()) {
				d += get_b_num(it.second, d + 1, child_num);
			}
		}
		return d;
	}

	int numFactoredBinaryTrees(vector<int>& arr) {
		map<int, bool> num;
		tree.clear();

		sort(arr.begin(), arr.end());
		for (auto it : arr) num[it] = true;

		for (int i = 0; i < arr.size(); ++i) {
			for (int j = 0; j < arr.size(); ++j) {
				if (num.find(arr[i] * arr[j]) != num.end()) {  // exist
					tree[arr[i] * arr[j]].push_back(pair<int, int>(arr[i], arr[j]));
				}
			}
		}

		// tree num :   Need to check by depth.. : XXXXX : 

		int tree_num = 0; // tree.size(); // 1 depth tree 
		for (auto it : tree) {
			vector<int> child_num (100, 0);
			max_d = 0;
			get_b_num(it.first, 0, child_num); 
			for (int i = 0; i <= max_d; ++i) {
				tree_num += child_num[i];
			}
		}

		int ans = arr.size() + tree_num;
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	//vector<int> fronts = { 1, 2, 4, 4, 7 };
	//vector<int> backs = {1, 3, 4, 1, 3};

	//vector<int> arr = { 2, 4,5 , 10 };
	vector<int> arr = { 18, 3, 6, 2};
	//vector<int> arr = { 4, 2 };

	cout << sol.numFactoredBinaryTrees(arr);


	//	cout << sol.countHighestScoreNodes(parents) << endl;
	//	cout << "test : " << ans << endl;

	cin >> c;
}