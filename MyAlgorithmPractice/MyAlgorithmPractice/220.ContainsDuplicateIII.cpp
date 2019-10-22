// 이건은 시간내서 한번더 들르자... 
// Multiset 사용하는 방법하고....  etc  관련 확인 필요 

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:

	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

		if (nums.size() <= 1) { return false; }

		multiset<long long> aSet;
		multiset<long long>::iterator aIter;

		for (int i = 0; i < nums.size(); i++) {
			if (i > k) { aSet.erase(nums[i - k - 1]); }
			aIter = aSet.lower_bound((long long)nums[i] - (long long)t);
			if (aIter != aSet.end()) {
				if (abs((long long)nums[i] - *aIter) <= (long long)t) {
					return true;
				}
			}
			aSet.insert((long long)nums[i]);
		}
		return false;
	}
};

int main() {
	Solution sol;
	char c;
	multiset<int> aset;
	multiset<int>::iterator aiter;
	//vector<int> v = { 1, 2, 3, 1 };
	vector<int> v = { 4,3,2,5,6,1,7,9};
	//vector<int> v = { -1, -1 };
	//vector<int> v = { -1,2147483647};


//	cout << sol.containsNearbyAlmostDuplicate(v, 1, -1);

	for (auto it : v) {
		aset.insert(it);
	}

	aiter = aset.lower_bound(4);
	aiter = aset.lower_bound(10);



	cin >> c;
}