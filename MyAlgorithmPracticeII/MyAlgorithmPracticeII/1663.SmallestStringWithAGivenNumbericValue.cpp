//  easy 
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
    string getSmallestString(int n, int k) {
        vector<int> v(n, 1);

        int r = k - n;
        for (int i = v.size() - 1; i >= 0; --i) {
            if (r >= 25) {
                r -= 25;
                v[i] = 26;
            }
            else {
                v[i] = r + 1;
                break;
            }
        }


        string ans;
        for (auto& it : v) {
            ans.push_back(it + 'a' - 1);
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    cout << sol.getSmallestString(5, 73);

    cin >> c;
}