// ok : �̰� �Ǵ°� �� �ű���. 
// �տ��� �ڷ� �߰��鼭 operation�ϴ°��� Optimal �̶�� �̾߱� ���.. 
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

//��¥.. �̰� �ȴٴ� ���ΰ�????
class Solution {
public:
    int solve(vector<int> a, int target) {
        int n = a.size();
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] != target) {
                cnt++;
                a[i] = -a[i];
                a[i + 1] = -a[i + 1];
            }
        }
        // If last element matches target, return flips; otherwise no solution
        return (a[n - 1] == target ? cnt : INT_MAX);
    }

    bool canMakeEqual(vector<int>& nums, int k) {
        // Try making all 1s or all -1s
        return solve(nums, 1) <= k || solve(nums, -1) <= k;
    }
};

int main() {
    char c;
    Solution sol;

    //vector<int> nums = { 23, 2, 4, 6, 7 };
    //vector<int> nums = { 23,2,6,4,7 };
    //vector<int> nums = { 1, 0 };
    vector<int> nums = { 23,2,4, 6, 6 };

    cout << sol.checkSubarraySum(nums, 7);

    cin >> c;
}