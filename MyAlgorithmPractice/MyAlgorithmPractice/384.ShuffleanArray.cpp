#include <iostream>
#include <unordered_set>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

class Solution {
public:
	vector<int> n;

	Solution(vector<int>& nums) {
		n = nums;
		srand(time(NULL));
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return n;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> t = n;
		vector<int> ans;
		int s = t.size();
		//srand(time(NULL));

		for (int i = 0; i < s; ++i) {
			int r1 = rand() % t.size();
			ans.push_back(t[r1]);
			t.erase(t.begin() + r1);
		}
		return ans;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

int main() {
	char c;
	vector<int> nums = { 1, 2, 3, 4, 5, 6 };
	Solution* obj = new Solution(nums);
	vector<int> param_1 = obj->reset();

	for (auto it : param_1) {
		cout << it << " ";
	}
	cout << endl;

for(int i = 0; i < 5; ++i) {
	vector<int> param_2 = obj->shuffle();
	for (auto it : param_2) {
		cout << it << " ";
	}
	cout << endl;

}
	cin >> c;
}
