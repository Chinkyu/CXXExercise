// let's skip....  
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


//:: timeout... 
class _Solution {
public:

    bool isWonderful(vector<int>& m) {
        int cnt = 0;
        for (int i = 0; i < m.size(); ++i) {
            if (m[i] % 2 == 1) {
                cnt++;
            }
        }

        if (cnt <= 1) {
            return true;
        }
        return false;
    }


    long long wonderfulSubstrings(string word) {
        int l = word.size();
        vector<int> m(10, 0);

        long long ans = 0;
        for (int i = 0; i < l ; ++i) {
            for (int j = i; j < l; ++j) {
                m[word[j] - 'a']++;
                if (isWonderful(m)) {
                    ans++;
                }
           }
            //m[word[i] - 'a']--;
            std::fill(m.begin(), m.end(), 0);
        }

        return ans;
    }
};


class Solution {
public:

    bool isWonderful(int m) {
        if (m == 0 || m == 1 || m == 2 || m == 4 || m == 8 ||
            m == 16 || m == 32 || m == 64 || m == 128 || m == 256 || m == 512) {
            return true;
        }
        return false;
    }


    long long wonderfulSubstrings(string word) {
        int l = word.size();
        int m = 0;

        long long ans = 0;
        for (int i = 0; i < l; ++i) {
            for (int j = i; j < l; ++j) {
                m ^= (1 << word[j] - 'a');
                if (isWonderful(m)) {
                    ans++;
                }
            }
            
            m = 0;
        }

        return ans;
    }
};



int main() {
    char c;
    Solution sol;

    string word = "fiabhedce";
        // "aabb";

    cout << sol.wonderfulSubstrings(word);


    cin >> c;
}
