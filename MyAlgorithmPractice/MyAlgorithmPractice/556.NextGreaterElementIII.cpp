#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int i, j, temp;
		// find right most sink
		int size = nums.size();
		if (size <= 1) return;

		int sink = -1;

		for (i = size - 1; i > 0; --i) {
			if (nums[i - 1] < nums[i]) {
				sink = i - 1;
				break;
			}
		}

		//		int sw = size - 1;
		if (sink >= 0) {
			for (i = sink + 1; i < size; ++i) {
				if (nums[i] <= nums[sink]) {
					//					sw = i-1;
					break;
				}
			}

			temp = nums[sink];
			nums[sink] = nums[i - 1];
			nums[i - 1] = temp;
		}

		for (i = sink + 1, j = size - 1; i < sink + 1 + ((size - 1) - (sink + 1) + 1) / 2; ++i, --j) {
			temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
		}
	}

	int nextGreaterElement(int n) {
		long long ans = 0;

		string s = to_string(n);

		vector<int> num;
		for (auto it : s) {
			num.push_back(it - '0');
		}

		nextPermutation(num);

		for (long long i = num.size() - 1, j = 1; i >= 0; --i, j *= 10) {
			ans += num[i] * j;
		}
		return (ans > INT_MAX || ans <= n) ? -1 : ans;
	}
};

int main() {
	char c;
	int n = 21;
	Solution sol;

	cout << sol.nextGreaterElement(n);

	cin >> c;
}