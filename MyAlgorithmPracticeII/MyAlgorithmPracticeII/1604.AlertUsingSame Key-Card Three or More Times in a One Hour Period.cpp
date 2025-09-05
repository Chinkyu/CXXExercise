// ok 
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
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        int l = keyName.size();
        unordered_map<string, vector<int>> m;

        for (int i = 0; i < l; ++i) {
            int t = ((keyTime[i][0] - '0') * 10 + (keyTime[i][1] - '0')) * 60;
            t += (keyTime[i][3] - '0') * 10 + (keyTime[i][4] - '0');

            m[keyName[i]].push_back(t);
        }
        vector<string> ans;
        for (auto& it : m) {
            vector<int> seq = it.second;
            sort(seq.begin(), seq.end());

            for (int i = 0; i + 2 < seq.size(); ++i) {
                if (seq[i + 2] - seq[i] <= 60) {
                    ans.push_back(it.first);
                    break;
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<string> keyName = { "daniel", "daniel", "daniel", "luis", "luis", "luis", "luis" };
    vector<string> keyTime = {"10:00", "10:40", "11:00", "09:00", "11:00", "13:00", "15:00"};

    vector<string> ans = sol.alertNames(keyName, keyTime);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}