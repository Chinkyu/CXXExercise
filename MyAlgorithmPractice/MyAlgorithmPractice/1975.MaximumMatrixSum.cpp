//  답봤음 : 왜 그런지 모르겠음..??
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

class Solution {
public:
	long long maxMatrixSum(vector<vector<int>>& matrix) {
		long long mn = INT_MAX, cnt = 0, sum = 0;
		for (auto r : matrix) {
			for (int i : r) {
				if (i < 0) cnt++;
				mn = min(mn, (long long)abs(i));
				sum += abs(i);
			}
		}
		return cnt % 2 ? sum - 2 * mn : sum;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> nums1 = { 0, 1, 1 }; // { 1, 1, 0, 1 };
	vector<int> nums2 = { 1, 0, 1 };// { 0, 1, 1, 0 };

	cout << sol.widestPairOfIndices(nums1, nums2);

	cin >> c;
}