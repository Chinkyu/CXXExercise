// dp
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
    int minExtraChar(string s, vector<string> dictionary) {
        int n = s.length();
        unordered_set<string> dictionarySet(dictionary.begin(), dictionary.end());
        unordered_map<int, int> memo;

        function<int(int)> dp = [&](int start) {
            if (start == n) {
                return 0;
            }
            if (memo.count(start)) {
                return memo[start];
            }
            // To count this character as a left over character 
            // move to index 'start + 1'
            int ans = dp(start + 1) + 1;
            for (int end = start; end < n; end++) {
                auto curr = s.substr(start, end - start + 1);
                if (dictionarySet.count(curr)) {
                    ans = min(ans, dp(end + 1));
                }
            }

            return memo[start] = ans;
            };

        return dp(0);
    }
};


// not work because the order matter. => DP 
class _Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {

        // Sort from longest to shortest
        sort(dictionary.begin(), dictionary.end(), [](const std::string& a, const std::string& b) {
            return a.size() > b.size();
            });

        for (auto& it : dictionary) {
            // Replace all instances of dictionar with an empty string
            string under_score(it.size(), '_');
            s = regex_replace(s, regex(it), under_score);
        }

        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '_') ans++;
        }

        return ans;

    }
};

int main() {
    char c;
    Solution sol;

    string s = "aakodubkrlauvfkzje";
    vector<string> dictionary = { "ix","qoqw","ax","ar","v","hxpl","nxcg","thr","kod","pns","cdo","euy","es","rf","bxcx","xe","ua","vws","vumr","zren","bzt","qwxn","ami","rrbk","ak","uan","g","vfk","jxmg","fhb","nqgd","fau","rl","h","r","jxvo","tv","smfp","lmck","od" };

    cout << sol.minExtraChar(s, dictionary);

    cin >> c;
}
