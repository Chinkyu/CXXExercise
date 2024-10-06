// easy :  좀 거지 같아서...skip
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
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> m;// A map to store whether the particular name occurs how many times already
        for (int i = 0; i < names.size(); i++)
        {
            if (m.find(names[i]) != m.end())// if the name already came
            {
                int k = m[names[i]];// it contains the number in brackets
                while (m.find(names[i] + "(" + to_string(k) + ")") != m.end())
                {
                    k++;// Increase number until that didn't exist
                    m[names[i]]++;//mean while update in the map too
                }
                m[names[i]]++;// Recently we will use one more number so increment
                names[i] = names[i] + "(" + to_string(k) + ")";
            }
            m[names[i]] = 1;// Here we are storing  for example ...abc(1)=1 and abc(2)=1 it means abc(1) occcured one time, and abc=2 it means abc occured 2 times.
            /*
            Suppose you have a file named ABC occurring twice, we will store ABC with occurrence =2 and ABC(1) with occurrence =1... It helps when we get another file with name ABC(1) we can store like ABC(1)(1)
            */

        }
        return names;
    }
};


class _Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> m;

        vector<string> ans;
        for (auto& it : names) {
            istringstream iss(it);

            string token, ntoken;
            int n = 0;

            getline(iss, token, '(');

            if (it.size() != token.size()) { // have braces
                getline(iss, ntoken, ')');
                n = stoi(ntoken);

                if (m.find(it) != m.end()) {  // already existing braces?
                    m[it]++;
                    ans.push_back(it + "(" + to_string(m[it]) + ")");
                    m[it + "(" + to_string(m[it]) + ")"] = 0;
                    continue;
                }

                // check no braces name exist
                if (m.find(token) != m.end()) {  // already existing braces?
                    m[token] = max(m[token], n);
                    m[it] = 0;
                    ans.push_back(it);
                }
                else {  // not exist
                    m[it] = 0;
                    ans.push_back(it);
                }
                continue;
            }

            // have no braces

            if (m.find(token) != m.end()) { // exist
                //m[token] = max(m[token], n);
                m[token]++;
                ans.push_back(token + "(" + to_string(m[token]) + ")");
                m[token + "(" + to_string(m[token]) + ")"] = 0;
            }
            else { // not exist
                m[token] = 0;
                ans.push_back(token);
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<string> names = { "onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece" };
    vector<string> ans = sol.getFolderNames(names);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}