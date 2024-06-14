// its ok : low_bound  이렇게 사용하기.. 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>
#include <set>
#include <regex>
#include <memory>

using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		map<int, int> m;

		m[1] = INT_MAX;

		for (auto& it : nums) {
			if (it <= 0) continue;

			auto itlow = m.lower_bound(it);
			//  이게 사용 하는 방법임
			// 같지 않으면 앞으로 한칸 가야함 
			if (itlow == m.end() ||
				(itlow != m.begin() && itlow->first != it)) {
				itlow--;
			}

			if (itlow->first == it) {
				if(it != itlow->second) m[it + 1] = itlow->second;
				m.erase(itlow);
			}
			else if (itlow->first < it  && it < itlow->second) {
				m[it + 1] = itlow->second;
				m[itlow->first] = it - 1;

			}
			else if (it == itlow->second) {
				if (itlow->first == it) {
					m.erase(itlow);
				}
				else {
					m[itlow->first] = it - 1;
				}

			}
		}

		return m.begin()->first;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> nums = { 1,2,6,3,5,4 };
	//{ 3,4,-1,1 };

	cout << sol.firstMissingPositive(nums);

	cin >> c;
}