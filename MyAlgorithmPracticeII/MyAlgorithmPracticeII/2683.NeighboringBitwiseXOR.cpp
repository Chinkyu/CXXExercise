//  ¥‰∫√¿Ω  : 
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
    bool doesValidArrayExist(vector<int>& derived) {
        return !accumulate(derived.begin(), derived.end(), 0, bit_xor<int>());
    }
};

int main() {
    char c;
    Solution sol;
    //vector<int> nums = { 2, 1, 3, 2, 1 };
    vector<int> nums = { 3, 1, 2 };


    cout << sol.minimumOperations(nums);

    cin >> c;
}