#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
//	bool less(int a, int b) { return a < b; }

	int findKthLargest(vector<int>& nums, int k) {
		vector<int> h;

		for (int i = 0; i < k; ++i) h.push_back(nums[i]);
		make_heap(h.begin(), h.end(), [](int a, int b) { return a > b; }); // , less);

		for (int i = k; i < nums.size(); ++i) {
			if (h.front() < nums[i]) {
				pop_heap(h.begin(), h.end(),[](int a, int b) { return a > b; }); 
				h.pop_back();
				
				h.push_back(nums[i]); 
				push_heap(h.begin(), h.end(), [](int a, int b) { return a > b; });
			}
		}
		return h.front();
	}
};

int main() {
	Solution sol;
	char c;
	vector<int> v = { 3, 2, 1, 5, 6, 4 };

	cout << sol.findKthLargest(v, 4);
	cin >> c;
}