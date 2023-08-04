// �亸�� ��������... �ű��ϰ� ���ϰ� �յ� �ű��ϰ���...��.. 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <cmath>

using namespace std;

class Solution {
public:
	int sumDistance(vector<int>& nums, string s, int d) {
		vector<int> dr;
//		for (auto it : s) {
//			if (it == 'L') dr.push_back(-1);
//			else dr.push_back(1);
//		}

#if 0  //   �̰�Ÿ�Ӿƿ�
		for (int i = 0; i < d; ++i) {
			for (int j = 0; j < nums.size(); ++j) {
//				if(j < d - 1 && nums[j] == nums[j + 1]) {
//					nums[j]--;
//					nums[j + 1]++;
//					j++;
//					continue;
//				}
				nums[j] = s[j] == 'L' ? nums[j] - 1 : nums[j] + 1;
			}
		}
#else
		for (int i = 0; i < nums.size(); ++i) {
				nums[i] = (s[i] == 'L') ? nums[i] - d : nums[i] + d;
		}

#endif


		//  �Ʒ����� Ÿ�Ӿƿ��ε�.. 1loop  �� ����� ������ �ִ�..
#if 0
		int dist = 0;
		for (int i = 0; i < nums.size() - 1; ++i) {
			for (int j = i + 1; j < nums.size(); ++j) {
				dist += abs(nums[i] - nums[j]);
				dist %= 1000000007;
			}
		}
#else  //  �� �ű��� �����̴�..
		long long dist = 0;
		long prefix = 0;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); ++i) {
			dist = (dist + i * (long)nums[i] - prefix) % 1000000007;
			prefix += nums[i] % 1000000007;

		}
#endif 

		return dist;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> nums = { -2, 0, 2 };
	string s = "RLL";
	cout << sol.sumDistance(nums, s, 3);
	//cout << sol.longestString(3, 25, 48);

	cin >> c;
}
