#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class _Solution {
public:

	bool overlap(int &s1, int &e1, int &s2, int &e2) {
		if (e1 < s2 || e2 < s1) {
			return false;
		}

		/* s1   XXX     e1*/
		if (s1 <= s2 && e2 <= e2) {
			s1 = s2;
			e1 = e2;
		}
		/* s2   XXX     e2*/
		else if (s2 <= s1 && e1 <= e2) {

		}

		/* s1   XX e1 XX */
		else if (s2 <= e2) {
			s1 = s2;
		}

		/* XX s1 XX    e1*/
		else if (s2 <= s1 ) {
			e1 = e2;
		}
		return true;
	}
	int minMoves2(vector<int>& nums) {
		int l = nums.size();
		int avg = 0, sum = 0;
		int st, ed;

		st = nums[0];
		ed = nums[0] + l - 1;

		for (int i = 1; i < l; ++i) {
			int tst = nums[i] - 1;
			int ted = nums[i] + l - i - 1;
			// nums[i] -i, nums[i] + l - i - 1;

			if (overlap(st, ed, tst, ted) == false) return 0;
		}


		for (auto it : nums) sum += it;
		avg = sum / l;

		int edge = 0;
		if (avg < st) {
			edge = st;
		}
		else if (st <= avg && avg <= ed) {
			edge = avg;
		}
		else {
			edge = ed;
		}

		int distance = 0;
		for (auto it : nums) distance += abs(it - edge);
		
		//cout << st << " " << ed << endl;

		return distance;
	}
};

class Solution {
public:
	int minMoves2(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		/* Sort the vector to find the median. Note that though this takes O(nlogn) time, it can be done in O(n) using Quick Select Algorithm.*/

		int median = nums[nums.size() / 2]; // Works for both odd and even number of elements
		int res = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			res += abs(nums[i] - median); // How far is each element from median
		}
		return res;
	}
};

int main() {
	char c;
	Solution sol;
	//vector<int> v = { 1, 2, 3 };
	vector<int> v = { 2, 1 };

	cout << sol.minMoves2(v);

	cin >> c;
}
