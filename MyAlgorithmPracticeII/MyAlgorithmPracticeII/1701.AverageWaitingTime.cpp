// easy : easy rather than think
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

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int l = customers.size();

        long long delay = 0;
        int time = 0;
        for (int i = 0; i < l; ++i) {

            if (customers[i][0] < time) {
                time += customers[i][1];
                delay += time - customers[i][0];
            }
            else if (time <= customers[i][0]) {
                time = customers[i][0] + customers[i][1];
                delay += customers[i][1];
            }
        }

        return delay / ((double)l);
    }
};



int main() {
    Solution sol;
    char c;
    vector<vector<int>> customers = { {1, 2},{2, 5},{4, 3}};
    cout << sol.averageWaitingTime(customers);


    cin >> c;
}
