#include <iostream>
#include <vector>
#include <map>

using namespace std;


//  2차원 배열로 나머지를 구해가면서 하는.....  Not good solution 
class Solution1 {
public:
	int st_idx;
	int ed_idx;
	bool checkSubarraySum(vector<int>& nums, int k) {
		vector<vector<int>> acc(nums.size(), vector<int>(nums.size()));

		if (k == 0) {
			// special check for zero
			for (int i = 0; i < nums.size()-1; i++) {
				if (nums[i] == 0 && nums[i + 1] == 0) return true;
			}
			return false;
		}

		if (k < 0) k = 0 - k;
		// mode k
//		for (int i = 0; i < nums.size(); i++) {
//			nums[i] %= k;
//		}

		// init acc
		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < nums.size(); j++) {
				acc[i][j] = 0;
			}
		}

		//  뒤에서 부터 Accumulation 하는 방식으로 누적해서 계산해 가는 방법....  =>   Memory Limit Exceed.... !!! 
		for (int i = nums.size() - 1; i >= 0; i--) {
			acc[i][i] = nums[i];
			for (int j = i + 1; j <= nums.size() - 1; j++) {
				acc[i][j] = (acc[i][i] + acc[i + 1][j]) % k;
				if (acc[i][j] == 0) {
					st_idx = i;
					ed_idx = j;
					return true;
				}
			}
		}
		return false;
	}
};


// 처음부터 나머지를 구해가는데... 나머지가 중복해서 나오면  Bingo...  - count variable 사용함
// count vector 를 사용하면  K 가  큰 값이 나올때  bad allocation 이 발생 =>  map 사용
class Solution2 {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		
		if (k == 0) {
			// special check for zero
			for (int i = 0; i < nums.size() - 1; i++) {
				if (nums[i] == 0 && nums[i + 1] == 0) return true;
			}
			return false;
		}

		if (k < 0) k = 0 - k;


		vector<int> acc(k, 0);

		int sum = 0;
		int mod = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			mod = sum % k;
			if (mod == 0) return true;

			acc[mod]++;
			if (acc[mod] >= 2) return true;
		}
		return false;
	}
};

class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {

		if (k == 0) {
			// special check for zero
			for (int i = 0; i < nums.size() - 1; i++) {
				if (nums[i] == 0 && nums[i + 1] == 0) return true;
			}
			return false;
		}

		if (k < 0) k = 0 - k;


		map<int,int> acc;

		int sum = 0;
		int mod = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			mod = sum % k;
			if (sum != 0 && mod == 0 && i > 0) return true;

			acc[mod]++;
			if (nums[i] > 0 && acc[mod] >= 2) return true;
		}
		return false;
	}
};

int main() {
	char c;
	vector<int> v = { 23, 2, 4, 6, 7 };
	vector<int> v1 = { 23, 2, 6, 4, 7 };
	vector<int> v3 = { 1000000000};
	Solution sol;

	cout << sol.checkSubarraySum(v1, 1000000000);
//	cout << " " << sol.st_idx << " " << sol.ed_idx;

	cin >> c;

}