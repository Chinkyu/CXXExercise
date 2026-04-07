// see answer... 
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


// if  large and small..  large -1 : mark  and afer mark all 9
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string n_str = to_string(N);

        int marker = n_str.size();
        for (int i = n_str.size() - 1; i > 0; i--) {
            if (n_str[i] < n_str[i - 1]) {
                marker = i;
                n_str[i - 1] = n_str[i - 1] - 1;
            }
        }

        for (int i = marker; i < n_str.size(); i++) n_str[i] = '9';

        return stoi(n_str);
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> arr = { 1, 3, 5 };

    cout << sol.numOfSubarrays(arr);

    cin >> c;
}
