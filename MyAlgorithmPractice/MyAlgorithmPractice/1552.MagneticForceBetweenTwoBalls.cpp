//  바이너리 서치로 가능 하다는데..... 참... ]
// 앞에서 해 보기.. 를 가격으로 선택 하면서.... 

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
	int n, c;
	vector<int> a;

	bool check(int k)
	{
		int cows = 1;
		int lt = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] - a[lt] >= k) {
				lt = i;
				cows++;
				if (cows == c) return true;
			}
		}
		return false;
	}

	int maxDistance(vector<int>& position, int m) {
		a = position;
		n = a.size();
		c = m;
		sort(a.begin(), a.end());
		int l = 0;
		int r = a[n - 1] - a[0];

		while (l <= r) {
			int mid = (l + r) / 2;
			if (check(mid)) l = mid + 1;
			else r = mid - 1;
		}
		return l - 1;
	}
};

int main() {
	char c;
	Solution sol;

	string s = "AAAAAAAAAAA"; //  "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"; //  "011010";
	vector<string> v = sol.findRepeatedDnaSequences(s);

	for (auto it : v) {
		cout << it << endl;
	}

	cin >> c;
}







