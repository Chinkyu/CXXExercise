// ok : use std::shuffle..  

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

class Solution {
public:
    vector<int> n, origin;
    Solution(vector<int>& nums) {
        origin = n = nums;
    }

    vector<int> reset() {
        n = origin;
        return n;
    }

    vector<int> shuffle() {
        // 1. Seed the generator using a time-based value for better randomness across runs
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 g(seed); // Using Mersenne Twister engine

        std::shuffle(n.begin(), n.end(), g);
        return n;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

int main() {
    char c;
    Solution sol;

    //    vector<int> nums = { 1,2,5,9 };
    //    cout << sol.smallestDivisor(nums, 6);

    vector<int> nums = { 200,100,14 };
    cout << sol.smallestDivisor(nums, 10);


    cin >> c;
}
