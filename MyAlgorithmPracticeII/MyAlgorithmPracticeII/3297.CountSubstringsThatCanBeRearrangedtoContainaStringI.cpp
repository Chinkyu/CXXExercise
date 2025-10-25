// ok : but it need to sort vector that doesn't spefied in problem 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
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



int main() {
    Solution sol;
    char c;

    vector<int> nums = { 1, 2, 2 };

    vector<vector<int>> ans = sol.subsetsWithDup(nums);
    for (auto& it : ans) {
        for (auto& jt : it) {
            cout << jt << " ";
        }
        cout << endl;
    }


    cin >> c;
}
