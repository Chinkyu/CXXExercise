// ok.  : use map, vector... etc 
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
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int l = creators.size();
        map<string, long long> ctr;
        map<string, pair<string, int>> hivideo;

        for (int i = 0; i < l; ++i) {
            ctr[creators[i]] += views[i];

            if (hivideo.find(creators[i]) != hivideo.end()) {
                if (hivideo[creators[i]].second < views[i]) {
                    hivideo[creators[i]].first = ids[i];
                    hivideo[creators[i]].second = views[i];
                }
                else if (hivideo[creators[i]].second == views[i] && ids[i] < hivideo[creators[i]].first) {
                    hivideo[creators[i]].first = ids[i];
                    hivideo[creators[i]].second = views[i];
                }
            }
            else {
                hivideo[creators[i]] = make_pair(ids[i], views[i]);
            }
        }

        vector<string> mcreator;
        long long mcreator_val = 0;
        for (auto it : ctr) {
            if (it.second > mcreator_val) {
                mcreator.clear();
                mcreator.push_back(it.first);
                mcreator_val = it.second;
            }
            else if (it.second == mcreator_val) {
                mcreator.push_back(it.first);
            }
        }

        vector<vector<string>> ans;
        for (int i = 0; i < mcreator.size(); ++i) {
            vector<string> tstr = { mcreator[i], hivideo[mcreator[i]].first };
            ans.push_back(tstr);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    char c;
    vector<string> creators = { "alice", "bob", "alice", "chris" };
    vector<string> ids = { "one", "two", "three", "four" };
    vector<int> views = { 5, 10, 5, 4 };

    vector<vector<string>> ans = sol.mostPopularCreator(creators, ids, views);

    for (auto it : ans) {
        cout << it[0] << " " << it[1] << endl;
    }


    cin >> c;
}
