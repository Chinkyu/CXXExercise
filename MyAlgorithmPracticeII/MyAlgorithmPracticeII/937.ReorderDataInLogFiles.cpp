// ok : 

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

    // return isDisit log
    bool GetKeyLog(string& fulllog, string& key, string& log) {
        int indent_idx = 0;
        for (int i = 0; i < fulllog.size(); ++i) {
            if (fulllog[i] == ' ') {
                key = fulllog.substr(0, i);
                log = fulllog.substr(i+1);
                break;
            }
        }

        for (int i = 0; i < log.size(); ++i) {
            if(log[i] != ' ' && !std::isdigit(log[i])) return false;
        }
        return true;
    }


    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<vector<string>> llog, dlog;

        for (auto i = 0; i < logs.size(); ++i) {
            string key, log;
            bool isDigitLog = GetKeyLog(logs[i], key, log);

            if (isDigitLog) {
                dlog.push_back({ logs[i] });
            }
            else {
                llog.push_back({ key, log });
            }
        }

        sort(llog.begin(), llog.end(),
            [](vector<string>& l, vector<string>& r) {
                if (l[1] == r[1]) {
                    return l[0] < r[0];
                }
                return l[1] < r[1];
            }
        );

        vector<string> ans;
        for (int i = 0; i < llog.size(); ++i) {
            ans.push_back(llog[i][0] + " " + llog[i][1]);
        }
        for (int i = 0; i < dlog.size(); ++i) {
            ans.push_back(dlog[i][0]);
        }

        return ans;

    }
};

int main() {
    char c;
    Solution sol;
    vector<string> logs = { "dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero" };

    vector<string> ans = sol.reorderLogFiles(logs);

    for (auto& it : ans) {
        cout << it << endl;
    }

    cin >> c;
}