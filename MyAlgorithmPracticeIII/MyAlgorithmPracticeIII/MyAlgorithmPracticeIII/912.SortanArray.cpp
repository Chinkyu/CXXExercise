// ok : some try and error 
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
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
};

int main() {
    char c;
    Solution sol;
    //string s = "2[abc]3[cd]ef3[cd]";
    //string s = "2[abc]zzzz";
    string s = "3[a2[c]]";

    //cout << sol.exchange(s, 5);
    cout << sol.decodeString(s);


    //cout << "Test  application";

    cin >> c;
}
