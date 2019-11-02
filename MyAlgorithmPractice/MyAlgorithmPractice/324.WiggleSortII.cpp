#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void _wiggleSort(vector<int>& nums) {
		vector<int> n = nums;
		int l = n.size();

		sort(n.begin(), n.end());
		nums.clear();

		for (int i = 0; i < l / 2; ++i) {
			nums.push_back(n[i]);
			nums.push_back(n[l - i - 1]);
		}
		if (l % 2 == 1) nums.push_back(n[l / 2]);
	}

	void wiggleSort(vector<int>& nums) {
		vector<int> n = nums;
		int l = n.size();

		sort(n.begin(), n.end());
		nums.clear();

//		for (int i = 0; i < l / 2; ++i) {
//			nums.push_back(n[i]);
//			if (l % 2 == 1) {
//				nums.push_back(n[l / 2 + i + 1]);
//			}
//			else {
//				nums.push_back(n[l / 2 + i]);
//			}		
//		}

		for (int i = 0; i < l / 2; ++i) {
			//nums.push_back(n[i]);
			//if (i % 2 == 1) {
			if (l % 2 == 1) {
				nums.push_back(n[l / 2 - i]);
			}
			else {
				nums.push_back(n[l / 2 - i -1]);
			}
			//}
			//else {
				nums.push_back(n[l - i - 1]);
			//}
		}
		if (l % 2 == 1) nums.push_back(n[0]);

//		for(int i = l -1, j = 0, k = i/2 + 1; i>=0; i--)
//			nums[i] = n[i & 1 ? k++ : j++];

	}
};

int main() {
	char c;
	Solution sol;
	vector<int> n = { 1, 5, 1, 1, 6, 4 };
	//vector<int> n = { 1, 3, 2, 2, 3, 1 };
	//vector<int> n = { 1, 1, 2, 1, 2, 2, 1};
	//vector<int> n = { 5, 3, 1, 2, 6, 7, 8, 5, 5 };
	//vector<int> n = { 4, 5, 5, 6 };

	sol.wiggleSort(n);

	for (auto it : n) {
		cout << it << " ";
	}
	cin >> c;
}