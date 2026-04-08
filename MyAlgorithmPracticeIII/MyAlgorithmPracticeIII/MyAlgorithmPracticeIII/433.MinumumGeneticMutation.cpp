// ok.. 
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

class Solution {
public:

    int diff(string& s1, string& s2) {
        int ans = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) ans++;
        }

        return ans;
    }


    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int l = bank.size();

        vector<bool> v(l, false);
        queue<string> q;
        q.push(startGene);

        int ans = 1;
        while (!q.empty()) {
            queue<string> tq;

            while (!q.empty()) {
                string s = q.front();
                q.pop();

                for (int i = 0; i < bank.size(); ++i) {
                    if (v[i] == false && diff(s, bank[i]) == 1) {
                        if (bank[i] == endGene) {
                            return ans;
                        }

                        v[i] = true;
                        tq.push(bank[i]);
                    }
                }
            }
            ans++;
            q = tq;
        };

        return -1;
    }
};

int main() {
    char c;
    Solution sol;

//    vector<string> arr = { "AACCGGTA","AACCGCTA","AAACGGTA" };
//    cout << sol.minMutation("AACCGGTT", "AAACGGTA", arr);

    vector<string> arr = { "AAAACCCC","AAACCCCC","AACCCCCC" };
    cout << sol.minMutation("AAAAACCC", "AACCCCCC", arr);


    cin >> c;
}
