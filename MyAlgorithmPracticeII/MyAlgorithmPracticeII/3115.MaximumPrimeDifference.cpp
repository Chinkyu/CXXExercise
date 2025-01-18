// Ok : 
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
    bool isPrime(int num) {

        if (num <= 1) return false;

        bool isPrime = true;

        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }

        return isPrime;
    }

    int maximumPrimeDifference(vector<int>& nums) {
        set<int> pm;
        int tminidx = 0, tmaxidx = 0;

        bool isFirst = true;
        for (int i = 0; i < nums.size(); ++i) {
            if (pm.find(nums[i]) != pm.end() || true == isPrime(nums[i])) {
                pm.insert(nums[i]);
                if (true == isFirst) {
                    tminidx = tmaxidx = i;
                    isFirst = false;
                }
                else {
                    tmaxidx = i;
                }
            }
        }

        return tmaxidx - tminidx;
        
    }
};


int main() {
    char c;
    Solution sol;
    vector<int> nums = { 4,2,9,5,3 };

    cout << sol.maximumPrimeDifference(nums);

    cin >> c;
}