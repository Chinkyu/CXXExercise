// tricky : stol overflow.. need to use string compare for sorting 

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
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int l = nums.size();
        unordered_map<int, vector<pair<string, int>>> m;
        vector<int> ans;

        for (int i = 0; i < queries.size(); ++i) {
            int trim_num = queries[i][1];
            vector<pair<string, int>> v;
            if (m.find(trim_num) == m.end()) {
                for (int i = 0; i < l; ++i) {
                    string s = nums[i].substr(nums[i].size() - trim_num);
                    v.push_back(make_pair(s, i));
                }

                sort(v.begin(), v.end(), [](pair<string, int>& l, pair<string, int>& r) {
                    if (l.first == r.first) {
                        return l.second < r.second;
                    }
                    for (int i = 0; i < l.first.size(); ++i) {
                        if (l.first[i] != r.first[i]) {
                            return l.first[i] < r.first[i];
                        }
                    }
                    return true;
                    });

                m[trim_num] = v;
                ans.push_back(v[queries[i][0] - 1].second);
            }
            else {
                ans.push_back(m[trim_num][queries[i][0] - 1].second);
            }
        }

        return ans;

    }
};


// long long 보다 사이즈가 커서... XX 
class _Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int l = nums.size();
        unordered_map<int, vector<pair<long long, int>>> m;
        vector<int> ans;

        for (int i = 0; i < queries.size(); ++i) {
            int trim_num = queries[i][1];
            vector<pair<long long, int>> v;
            if (m.find(trim_num) == m.end()) {
                for (int i = 0; i < l; ++i) {
                    string s = nums[i].substr(nums[i].size() - trim_num);
                    v.push_back(make_pair( stol(s), i));
                }

                sort(v.begin(), v.end(), [](pair<long long, int>& l, pair<long long, int>& r) {
                    if (l.first == r.first) {
                        return l.second < r.second;
                    }
                    return l.first < r.first;
                    });

                m[trim_num] = v;
                ans.push_back(v[queries[i][0] - 1].second);
            }
            else {
                ans.push_back(m[trim_num][queries[i][0] - 1].second);
            }
        }

        return ans;

    }
};

int main() {
    char c;
    Solution sol;
    vector<string> nums = { "102","473","251","814" };
    vector<vector<int>> queries = { {1,1}, {2,3}, {4, 2}, {1,2} };

    vector<int> ans = sol.smallestTrimmedNumbers(nums, queries);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}