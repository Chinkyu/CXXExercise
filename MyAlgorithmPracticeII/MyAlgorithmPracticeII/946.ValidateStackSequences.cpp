// ok : do logically 

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
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int l = pushed.size();
        stack<int> st;

        int pui = 0, poi = 0;

        for (int i = 0; i < l; ++i) {

            while (st.size() == 0 || st.top() != popped[i]) {
                if (pui >= l) return false;
                st.push(pushed[pui++]);
            }

            st.pop();
        }

        return true;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> pushed = { 1, 2, 3, 4, 5 };
    vector<int> popped = { 4, 5, 3, 2, 1 };

    cout << sol.validateStackSequences(pushed, popped);

    cin >> c;
}