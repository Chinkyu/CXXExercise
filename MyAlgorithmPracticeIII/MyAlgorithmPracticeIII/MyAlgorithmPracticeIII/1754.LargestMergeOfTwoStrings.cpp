// Ok.. : tricky when two substring is same... need compare with substring 
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

using namespace std;

class Solution {
public:
    string largestMerge(string word1, string word2) {

        int w1i = 0, w2i = 0;
        string ans;


        while (w1i < word1.size() || w2i < word2.size()) {

            if (w1i < word1.size() && w2i < word2.size()) {

                if (word1[w1i] > word2[w2i]) {
                    ans.push_back(word1[w1i++]);
                }
                else if (word1[w1i] < word2[w2i]) {
                    ans.push_back(word2[w2i++]);
                }
                else {  // == same : need to check nect character

#if 0
                    int tw1i = w1i, tw2i = w2i;
                    while (tw1i < word1.size() && word1[tw1i] == word1[w1i]) tw1i++;
                    while (tw2i < word2.size() && word2[tw2i] == word2[w2i]) tw2i++;

                    if (word1[tw1i] > word2[tw2i]) {
                        ans.push_back(word1[w1i++]);
                    }
                    else {
                        ans.push_back(word2[w2i++]);
                    }
#endif 

                    if(word1.substr(w1i) > word2.substr(w2i)) {
                        ans.push_back(word1[w1i++]);
                    }
                    else {
                        ans.push_back(word2[w2i++]);
                    }

                }
            }
            else if (w1i < word1.size()) {
                ans.push_back(word1[w1i++]);
            }
            else {  // word2 remained
                ans.push_back(word2[w2i++]);
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    string word1 = "cabaa", word2 = "bcaaa";
    cout << sol.largestMerge( word1, word2);


    cin >> c;
}
