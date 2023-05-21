// 잘몰라서 한글 설명을 봤음.... 

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
	int hIndex(vector<int>& citations) {
		int ans = 0;
		sort(citations.begin(), citations.end(), [](int l, int r) {  return l > r; });

		for (int i = 0; i < citations.size(); ++i) {
			if (citations[i] >= i+1) ans = i+1;
		}

		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> citations = { 3,0,6,1,5 };
	cout << sol.hIndex(citations);

	cin >> c;
}