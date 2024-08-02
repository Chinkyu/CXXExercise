// ¥‰∫√¿Ω : merge sort and sliding window???
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

class Solution :
    def countRangeSum(self, nums: List[int], lower : int, upper : int) -> int :
    prefix = nums.copy()
    for i in range(1, len(nums)) :
        prefix[i] += prefix[i - 1]
        self.count = 0
        for n in prefix :
if lower <= n <= upper :
    self.count += 1

    def merge(left_arr, right_arr) :
    # Step 1: counting pairs i, j
    start, end = 0, 0 # index of right_arr
    # loop though left_arr to fix i index
    for i in range(len(left_arr)) :
        # find the interval of start to end in right_arr
        # sliding windows[start, end]
        while start < len(right_arr) and right_arr[start] - left_arr[i] < lower:
start += 1
while end < len(right_arr) and right_arr[end] - left_arr[i] <= upper :
    end += 1
    self.count += end - start

    # Step 2: merge 2 sorted arr
    l, r = 0, 0
    sorted_arr = []
    while l < len(left_arr) and r < len(right_arr) :
        if left_arr[l] < right_arr[r] :
            sorted_arr.append(left_arr[l])
            l += 1
        else :
            sorted_arr.append(right_arr[r])
            r += 1
            return sorted_arr + left_arr[l:] + right_arr[r:]

            def divide(arr) :
            if len(arr) <= 1 : return arr
                mid = len(arr)//2
                left_arr = divide(arr[:mid])
                right_arr = divide(arr[mid:])
                return merge(left_arr, right_arr)

                divide(prefix)
                return self.count


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
