// ok : use sort.. only consequtive two number switched -> true
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
#include <random>
#include <chrono>
#include <iterator>

using namespace std;


// exception case 
class _Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int l = nums.size();

        int st = -1, ed = l;
        for (int i = 1; i < l; ++i) {
            if (nums[i - 1] > nums[i]) {  // decrease -> update st, ed
                if (st == -1) {
                    st = i - 1;
                    ed = i;
                }
                else {
                    return false; // continuous down make false
                    //ed = i;
                }
            }
            else {  // increase -> check 
                if (((0 < st) && (nums[st - 1] >= nums[ed])) ||
                    ((ed < l - 1) && (nums[st] >= nums[ed + 1]))) {
                    return false;
                }
                st = -1;
                ed = l;
            }
        }

        // need to check last
        if (((0 < st) && (nums[st - 1] >= nums[ed])) ||
            ((ed < l - 1) && (nums[st] >= nums[ed + 1]))) {
            return false;
        }

        return true;
    }
};

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int l = nums.size();
        
        vector<int> sn = nums;
        sort(sn.begin(), sn.end());

        for (int i = 0; i < l - 1; ++i) {
            if (nums[i] != sn[i]) {
                if ((sn[i + 1] != nums[i]) || (sn[i] != nums[i + 1])) {
                    return false;
                }
                i++;
            }
        }

        return true;
    }
};




int main() {
    char c;
    Solution sol;

    vector<int> nums = {1, 0, 2};
    // {1, 2, 0 };

    cout << sol.isIdealPermutation(nums);
    cin >> c;
}
