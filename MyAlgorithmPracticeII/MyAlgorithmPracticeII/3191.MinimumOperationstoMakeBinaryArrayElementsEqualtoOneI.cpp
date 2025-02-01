//  답참조 : 앞에서 하나씩 해나가서 마지막에 두개가 둘다 1 1 이 아니멸 -1 
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
#include <list>
#include <regex>
#include <memory>
#include <functional>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int sz = nums.size(), res = 0;
        for (int i = 0; i + 2 < sz; ++i)
            if (nums[i] == 0) {
                ++res;
                nums[i + 1] = !nums[i + 1];
                nums[i + 2] = !nums[i + 2];
            }
        return nums[sz - 1] && nums[sz - 2] ? res : -1;
    }
};

int main() {
	char c;
	Solution sol;
	string s = "aaab";

	cout << sol.reorganizeString(s);

	cin >> c;
}