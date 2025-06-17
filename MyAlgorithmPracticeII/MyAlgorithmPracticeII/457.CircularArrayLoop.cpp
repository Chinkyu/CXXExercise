// saw answer : there is solution to detect loop
//slow = next(nums, slow);
//fast = next(nums, next(nums, fast));
// if slow and fast meet -> Cycle
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

using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            int sign = (nums[i] > 0) ? 1 : -1;
            int k = ((i + nums[i]) % n + n) % n;
            if ((sign == 1 && nums[k] < 0) || (sign == -1 && nums[k] > 0))
                continue;
            while (k != i && cnt < n)
            {
                if (sign == 1 && (nums[k] < 0))
                    break;
                else if (sign == -1 && (nums[k] > 0))
                    break;
                int temp = ((k + nums[k]) % n + n) % n;
                k = temp;
                cnt++;
            }
            if (k == i && cnt >= 1)return true;
        }

        return false;
    }
};

int main() {
    char c;
    Solution sol;
    //vector<vector<int>> matrix = { {5, 2},{1, 6} };
    vector<vector<int>> matrix = { {10, 9, 5}, {2, 0, 4}, {1, 0, 9}, {3, 4, 8} };

    cout << sol.kthLargestValue(matrix, 10);

    cin >> c;
}