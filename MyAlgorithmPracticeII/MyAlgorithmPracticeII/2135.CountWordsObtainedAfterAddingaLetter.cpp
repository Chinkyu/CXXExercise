// See anser : timeout  -> need to use set
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



    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        // making set for stroring string

        unordered_set<string> st;

        for (int i = 0; i < startWords.size(); i++) {
            // sorting the string array
            sort(startWords[i].begin(), startWords[i].end());
            st.insert(startWords[i]);
        }


        int count = 0;
        for (int i = 0; i < targetWords.size(); i++) {
            string check = targetWords[i];
            sort(check.begin(), check.end());

            bool found = false;
            for (int i = 0; i < check.size(); i++) {
                string search = check.substr(0, i) + check.substr(i + 1);
                if (st.find(search) != st.end()) {
                    found = true;
                    break;
                }
            }
            if (found) count++;
        }
        return count;
    }
};

// timeout 
class _Solution {
public:

    bool isTargetHaveOne(unordered_map<char, int>& s, unordered_map<char, int> t) {

        for (auto &it : s) {
            t[it.first]--;
            if (t[it.first] < 0) return false;
        }

        int sum = 0;
        for (auto &it : t) {
            sum += it.second;
        }

        if (sum == 1) {
            return true;
        }
        else {
            return false;
        }
    }

    int wordCount(vector<string>& startWords, vector<string>& targetWords) {

        vector<unordered_map<char, int>> tm(targetWords.size());
        vector<unordered_map<char, int>> sm(startWords.size());

        for (int i = 0; i < targetWords.size(); ++i) {
            for (auto it : targetWords[i]) {
                tm[i][it]++;
            }
        }

        for (int i = 0; i < startWords.size(); ++i) {
            for (auto it : startWords[i]) {
                sm[i][it]++;
            }
        }

        int ans = 0;
#if 0
        for (int i = 0; i < startWords.size(); ++i) {
            for (int j = 0; j < targetWords.size(); ++j) {
                if (targetWords[j].size() != startWords[i].size() + 1) continue;

                if (true == isTargetHaveOne(sm[i], tm[j])) {
                    ans++;
                }
            }
        }
#endif
        for (int i = 0; i < targetWords.size(); ++i) {
            for (int j = 0; j < startWords.size(); ++j) {
                if (targetWords[i].size() != startWords[j].size() + 1) continue;

                if (true == isTargetHaveOne(sm[j], tm[i])) {
                    ans++;
                    break;
                }
            }
        }



        return ans;

    }
};

int main() {
    char c;
    Solution sol;
    //vector<string> startWords = { "ab","a" };
    //vector<string> targetWords = { "abc","abcd" };

    vector<string> startWords = { "g","vf","ylpuk","nyf","gdj","j","fyqzg","sizec" };
    vector<string> targetWords = { "r","am","jg","umhjo","fov","lujy","b","uz","y" };

    cout << sol.wordCount(startWords, targetWords);

    cin >> c;
}