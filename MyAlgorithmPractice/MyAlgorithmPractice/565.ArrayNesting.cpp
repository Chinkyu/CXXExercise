// 여러가지  Case를 좀더 확인해 보면 좋겠음

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int arrayNesting(vector<int>& a) {
		size_t maxsize = 0;
		for (int i = 0; i < a.size(); i++) {
			size_t size = 0;
			for (int k = i; a[k] >= 0; size++) {
				int ak = a[k];
				a[k] = -1; // mark a[k] as visited;
				k = ak;
			}
			maxsize = max(maxsize, size);
		}

		return maxsize;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> a = { 5, 4, 0, 3, 1, 6, 2 };


	cout << sol.arrayNesting(a);

	cin >> c;
}