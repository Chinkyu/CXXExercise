//제일 큰거를 앞으로 뒤집고... 전체 뒤집어서.. 큰값을 뒤에 두면서
// 하나씩 줄여가면 풀림... !! 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> ans;

	void flip(vector<int> &arr, int end) {
		
		for (int i = 0; i < (end+1) / 2; ++i) {
			int temp = arr[i];
			arr[i] = arr[end-i];
			arr[end - i] = temp;
		}
		ans.push_back(end+1);
	}

	void iterate(vector<int> &arr, int end) {
		int max_idx = 0, max = arr[0];
		for (int i = 0; i <= end; ++i) {
			if (max < arr[i]) {
				max = arr[i];
				max_idx = i;
			}
		}

		flip(arr, max_idx);
		flip(arr, end);
	}


	vector<int> pancakeSort(vector<int>& arr) {
		ans.clear();

		for (int i = arr.size() - 1; i >= 1; --i) {
			iterate(arr, i);
		}
		return ans;
	}
};

int main() {
	char c;

	Solution sol;
	vector<int> arr = { 3, 2, 4, 1 };
	vector<int> ans = sol.pancakeSort(arr);

	for (auto it : ans) {
		cout << " " << it;
	}
	cout << endl;

	cin >> c;
}