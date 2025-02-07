// easy : 

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
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int l = rooms.size();
        stack<int> st;
        vector<int> vv(l);

        for (auto& it : rooms[0]) {
            st.push(it);
        }
        vv[0] = 1;

        while (!st.empty()) {
            int idx = st.top();
            st.pop();
            if (vv[idx] == 0) {  // not visited
                for (auto& it : rooms[idx]) {
                    st.push(it);
                }
            }
            vv[idx] = 1;

        }

        for (int i = 0; i < l; ++i) {
            if (vv[i] == 0) return false;
        }

        return true;
    }
};

int main() {
    char c;
    Solution sol;
    vector<vector<int>> rooms = { {1}, {2}, {3}, {} };

    cout << sol.canVisitAllRooms(rooms);

    cin >> c;
}