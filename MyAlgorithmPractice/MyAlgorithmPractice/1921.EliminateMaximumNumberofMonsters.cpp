// ok.... 
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

using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int l = dist.size();

        // emlimiate first comer 
        vector<int> time(l, 0);
        for (int i = 0; i < l; ++i) {
            time[i] = ceil((double)dist[i] / speed[i]);
        }

        sort(time.begin(), time.end());

        for (int i = 0; i < l; ++i) {
            if (time[i] < i + 1) return i;
        }

        return l;
    }
};

int main() {
    char c;
    Solution sol;

    //vector<int> dist = { 1, 3, 4 };
    //vector<int> speed = { 1, 1, 1 };

    vector<int> dist = { 1, 1, 2, 3 };
    vector<int> speed = { 1, 1, 1, 1};

    cout << sol.eliminateMaximum(dist, speed);

    cin >> c;
}