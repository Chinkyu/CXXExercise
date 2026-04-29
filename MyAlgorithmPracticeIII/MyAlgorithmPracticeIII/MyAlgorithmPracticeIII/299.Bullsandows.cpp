// easy
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
    string getHint(string secret, string guess) {

        int bull = 0, cow = 0;
        unordered_map<int, int> m;

        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                bull++;
                guess[i] = 0;
            }
            else {
                m[secret[i]]++;  // add map
            }
        }

        for (int i = 0; i < guess.size(); ++i) {
            if (guess[i] != 0) {
                if (m.find(guess[i]) != m.end()) {
                    m[guess[i]]--;
                    cow++;
                    if (m[guess[i]] <= 0) {
                        m.erase(guess[i]);
                    }
                }
            }
        }

        string ans;
        ans.append(to_string(bull));
        ans.append("A");
        ans.append(to_string(cow));
        ans.append("B");

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    //vector<vector<int>> grid = { {6, 7}, {5, 8} };
    //vector<vector<int>> grid = { {2, 7, 5} };
    //vector<vector<int>> grid = { {26, 24, 3}, {2, 22, 17 } };

    cout << sol.getHint("1807", "7810");

    cin >> c;
}
