#include <iostream>
#include <vector>
#include <map>

using namespace std;


//  2���� �迭�� �������� ���ذ��鼭 �ϴ�.....  Not good solution 
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

		//  �ڿ��� ���� Accumulation �ϴ� ������� �����ؼ� ����� ���� ���....  =>   Memory Limit Exceed.... !!! 
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


// ó������ �������� ���ذ��µ�... �������� �ߺ��ؼ� ������  Bingo...  - count variable �����
// count vector �� ����ϸ�  K ��  ū ���� ���ö�  bad allocation �� �߻� =>  map ���
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