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

using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int l = customers.size();

        vector<int> f(l, 0), b(l, 0);

        int inc = 0;
        for (int i = 0; i < l; ++i) {
            if (customers[i] == 'N') ++inc;
            f[i] = inc;
        }

        int dec = 0;
        for (int i = l - 1; i >= 0; --i) {
            if (customers[i] == 'Y') dec++;
            b[i] = dec;
        }

        int tmin = INT_MAX;
        int min_idx = 0;
        for (int i = 0; i <= l; ++i) {
            int loss = 0;
            if (i == 0) {
                loss = b[i];
            }
            else if (i == l) {
                loss = f[i - 1];
            }
            else {
                loss = f[i - 1] + b[i];
            }
            
            if (tmin > loss) {
                tmin = loss;
                min_idx = i;
            }
        }

        return min_idx;
    }
};


int main() {
    char c;
    Solution sol;
    string customers = "YYYY";


    cout << sol.bestClosingTime(customers);

    cin >> c;
}