// Tricky.. : tricky debugging...... 
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
    vector<vector<string>> accountsMerge_internal(vector<vector<string>>& accounts) {
        int l = accounts.size();
        unordered_map<string, int> m;

        vector<string> ans_name;
        vector<set<string>> ans_email(l);
        int ans_idx = 0;
        for (int i = 0; i < accounts.size(); ++i) {
            int find_idx = -1;
            for (int j = 1; j < accounts[i].size(); ++j) {
                if (m.find(accounts[i][j]) != m.end()) {
                    // find existing index of ans
                    find_idx = m[accounts[i][j]];
                    break;
                }
            }

            if (find_idx != -1) {
                for (int j = 1; j < accounts[i].size(); ++j) {
                    ans_email[find_idx].insert(accounts[i][j]);
                    m[accounts[i][j]] = find_idx;
                }
            }
            else {  // not found
                ans_name.push_back(accounts[i][0]);
                for (int j = 1; j < accounts[i].size(); ++j) {
                    ans_email[ans_idx].insert(accounts[i][j]);
                    m[accounts[i][j]] = ans_idx;
                }
                ans_idx++;
            }
        }

        vector<vector<string>> ans;

        for (int i = 0; i < ans_idx; ++i) {
            vector<string> t_v;
            t_v.push_back(ans_name[i]);
            for (auto& it : ans_email[i]) {
                t_v.push_back(it);
            }
            ans.push_back(t_v);
        }

        return ans;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector < vector<string>> ans = accountsMerge_internal(accounts);
        vector<vector<string>> ans2;
        while(true) {
            ans2 = accountsMerge_internal(ans);
            if (ans2.size() == ans.size()) break;
            ans = ans2;
        }
        return ans2;
    }
};



int main() {
    char c;
    Solution sol;
    //vector<vector<string>> accounts = {{"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"John", "johnsmith@mail.com", "john00@mail.com"}, {"Mary", "mary@mail.com"}, {"John", "johnnybravo@mail.com"}};
    vector<vector<string>> accounts = {{"David", "David0@m.co", "David0@m.co", "David1@m.co", "David2@m.co", "David3@m.co", "David4@m.co", "David5@m.co", "David6@m.co", "David7@m.co"}, {"David", "David0@m.co", "David0@m.co", "David1@m.co", "David2@m.co", "David3@m.co", "David4@m.co", "David5@m.co", "David6@m.co", "David7@m.co"}, {"David", "David2@m.co", "David18@m.co", "David19@m.co", "David20@m.co", "David21@m.co", "David22@m.co", "David23@m.co", "David24@m.co", "David25@m.co"}, {"David", "David3@m.co", "David27@m.co", "David28@m.co", "David29@m.co", "David30@m.co", "David31@m.co", "David32@m.co", "David33@m.co", "David34@m.co"}, {"David", "David1@m.co", "David9@m.co", "David10@m.co", "David11@m.co", "David12@m.co", "David13@m.co", "David14@m.co", "David15@m.co", "David16@m.co"}};
    vector<vector<string>> ans =  sol.accountsMerge(accounts);

    for (auto& it : ans) {
        for (auto& jt : it) {
            cout << jt << " ";
        }
        cout << endl;
    }

    cin >> c;
}