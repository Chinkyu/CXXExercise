//  ¥‰∫√¿Ω : all map operation 
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
    string toLower(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (!(s[i] >= 'a' and s[i] <= 'z')) {
                s[i] = s[i] + 32;
            }
        }
        return s;
    }
    string toVowel(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                s[i] = '*';
            }
        }
        return s;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string, int>Exact;
        unordered_map<string, string>Capitalised;
        unordered_map<string, string>Vowel;
        for (auto word : wordlist) {
            Exact[word] = 1;
            string cap = toLower(word);
            if (Capitalised.count(cap) == 0)
                Capitalised[cap] = word;
            string cap1 = toVowel(cap);
            if (Vowel.count(cap1) == 0)
                Vowel[cap1] = word;
        }
        vector<string>ans;
        for (auto q : queries) {
            if (Exact.count(q)) {
                ans.push_back(q);
                continue;
            }
            else if (Capitalised.count(toLower(q))) {
                ans.push_back(Capitalised[toLower(q)]);
                continue;
            }
            else if (Vowel.count(toVowel(toLower(q)))) {
                ans.push_back(Vowel[toVowel(toLower(q))]);
                continue;
            }
            else {
                ans.push_back("");
            }
        }
        return ans;
    }
};


int main() {
    char c;
    Solution sol;

    vector<int> customers = { 1,0,1,2,1,1,7,5 };
    vector<int> grumpy = { 0,1,0,1,0,1,0,1 };

    cout << sol.maxSatisfied(customers, grumpy, 3);

    cin >> c;
}