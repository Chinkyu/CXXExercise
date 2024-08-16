// ¥‰∫√¿Ω : binary logic
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
    // Similar to book allocation

    bool solve(vector<int>& a, int mid, int n, int m)
    {
        int sc = 1;
        long long sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if (sum + a[i] > mid)
            {
                sc++;
                sum = a[i];
                if (sc > m || a[i] > mid) return false; //edge case
            }
            else
            {
                sum += a[i];
            }

        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
        }
        int s = 0;
        int e = sum;
        int ans = -1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (solve(nums, mid, n, k))
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return ans;

    }
};

int main() {
    Codec sol;
    char c;

    TreeNode* r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->right = new TreeNode(3);
    r->right->left = new TreeNode(4);
    r->right->right = new TreeNode(5);


    string ans = sol.serialize(r);
    cout << ans;

    TreeNode* root = sol.deserialize(ans);

    cin >> c;
}
