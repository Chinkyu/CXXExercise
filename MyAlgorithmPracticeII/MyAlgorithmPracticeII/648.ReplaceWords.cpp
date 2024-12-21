// easy : afraid timeout 
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
    string replaceWords(vector<string>& dictionary, string sentence) {
        int l = dictionary.size();
        sort(dictionary.begin(), dictionary.end());

#if 0
        for (int i = 0; i < l - 1; ++i) {
            if (dictionary[i] == "0000") continue;
            for (int j = i + 1; j < l; ++j) {
                if (dictionary[j] == "0000") continue;
                if (0 == dictionary[i].compare(0, dictionary[i].size(), dictionary[j])) {
                    dictionary[j] = "0000";
                }
            }
        }
#endif 
        istringstream iss(sentence);
        string token;
        string ans;

        getline(iss, token, ' ');  // for first /

        bool found = false;
        for (int i = 0; i < l; ++i) {
            if (0 == token.compare(0, dictionary[i].size(), dictionary[i])) {
                ans += dictionary[i] + " ";
                found = true;
                break;
            }
        }
        if (!found) {
            ans += token + " ";
        }

        while (getline(iss, token, ' ')) {
            found = false;
            for (int i = 0; i < l; ++i) {
                if (0 == token.compare(0, dictionary[i].size(), dictionary[i])) {
                    ans += dictionary[i] + " ";
                    found = true;
                    break;
                }
            }
            if (!found) {
                ans += token + " ";
            }
        }

        if (ans[ans.size() - 1] == ' ') ans.pop_back();
        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    //vector<string> dictionary = { "cat","bat","rat" };
    //string sentence = "the cattle was rattled by the battery";

    vector<string> dictionary = { "a","b","c" };
    string sentence = "aadsfasf absbs bbab cadsfafs";

    cout << sol.replaceWords(dictionary, sentence);

    cin >> c;
}