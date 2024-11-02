// Tricky : 문제이해가 좀 잘 안되지만...  이상한 문제임.... 
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
    int arrayNesting(vector<int>& nums) {

        //int max_start = -1;
        int max_num = 1;

        unordered_map<int, int> v;

        for (int i = 0; i < nums.size(); ++i) {

            int jmp = 1;
            int n = nums[i];
            v[i] = 1;
            //int start = n;
            while (v[n] != 1) {
                v[n] = 1;
                n = nums[n];
                jmp++;

                max_num = max(max_num, jmp);
            }

        }

        return max_num;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 0, 1, 2 }; // { 5, 4, 0, 3, 1, 6, 2 };
    cout << sol.arrayNesting(nums);

    cin >> c;
}