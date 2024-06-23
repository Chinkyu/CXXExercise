// tricky : many if case for handling exception case 
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
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int l = words.size();

        int len = words[0].size();
        int sti = 0, edi = 0;

        vector<string> ans;

        // only one 
        if (l == 1) {
            string s = words[0];
            s.insert(s.end(), maxWidth - s.size(), ' ');
            ans.push_back(s);

            return ans;
        }

        for (int i = 1; i < l; ++i) {

            if (len + words[i].size() + 1 > maxWidth) {
                // distribute space  and add line
                int spaceNum = edi - sti;
                int allSpace = maxWidth - len + spaceNum;

                // spaceNum == 0;
                if (spaceNum == 0) {
                    string s = words[sti];
                    s.insert(s.end(), maxWidth - s.size(), ' ');
                    ans.push_back(s);

                    len = words[i].size();
                    sti = i;
                    edi = i;
                    
                    if (i == l - 1 && len > 0) {
                        string s = words[sti];
                        s.insert(s.end(), maxWidth - s.size(), ' ');
                        ans.push_back(s);
                    }

                    continue;
                }

                int eS = allSpace / spaceNum;
                int shortSpaceNum = spaceNum - (allSpace - (eS * spaceNum));
                int longSpaceNum = allSpace - (eS * spaceNum);
                string s = words[sti];
                for (int j = sti + 1, k = 0; j <= edi; ++j, ++k) {
                    if (k < longSpaceNum) {
                        for(int ii = 0; ii < eS + 1; ++ii) s.append(" ");
                    }
                    else {
                        for (int ii = 0; ii < eS; ++ii) s.append(" ");
                    }
                    s.append(words[j]);
                }

                ans.push_back(s);

                len = words[i].size();
                sti = i;
                edi = i;
            }
            else {
                len += words[i].size() + 1;
                edi = i;
            }


            if (i == l - 1 && len > 0) {
                string s = words[sti];
                for (int j = sti + 1; j <= edi; ++j) {
                    s.append(" ");
                    s.append(words[j]);
                }

                s.insert(s.end(), maxWidth - s.size(), ' ');
                ans.push_back(s);
            }
        }

        return ans;
    }
};


class _Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        std::vector<std::string> sol;
        std::string plc;
        //Is better paradigm to just add the word (no assumed space, and then check the size when adding a space)?
        for (size_t i = 0; i < words.size(); i++) {
            if (i != 0 && plc.length() + words[i].length() + 1 > static_cast<size_t>(maxWidth)) {
                //Justify the line
                auto it = std::find(plc.begin(), plc.end(), ' ');
                //If only one word, left justified
                if (it == plc.end()) {
                    while (plc.length() < static_cast<size_t>(maxWidth)) {
                        it = plc.insert(it, ' ');
                    }
                }
                else { //If more than one, center justified
                    while (plc.length() < static_cast<size_t>(maxWidth)) {
                        it = plc.insert(it, ' '); //Insert space in the group of space characters
                        it = std::find_if(it, plc.end(), [](char c) {return c != ' '; });//Find next non-space
                        it = std::find(it, plc.end(), ' ');//Find next space
                        if (it == plc.end()) { //If no more space groups, back to the first one
                            it = std::find(plc.begin(), plc.end(), ' ');
                        }
                    }
                }

                //Append
                sol.push_back(plc);
                plc.clear();
                plc.append(words[i]); //First word in a line can always be appended
            }
            else {
                if (plc.size() == 0) { //First iteration only, probably
                    plc.append(words[i]);
                }
                else { //Append space (at least always one), then word
                    plc.append(1, ' ');
                    plc.append(words[i]);
                }
            }
        }
        //Justify last line
        auto it = plc.end();
        while (plc.length() < static_cast<size_t>(maxWidth)) {
            it = plc.insert(it, ' ');//Just insert spaces at the end
        }
        //Add to solution
        sol.push_back(plc);
        return sol;
    }
};

int main() {
    char c;
    Solution sol;

    //vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    //vector<string> words = { "What","must","be","acknowledgment","shall","be" };
    //vector<string> words = {"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"    };
    //vector<string> words = { "a" };
    vector<string> words = { "a","b","c","d","e" };

    vector<string> ans = sol.fullJustify(words, 1);

    for (auto& it : ans) {
        cout << it << endl;
    }


    cin >> c;
}