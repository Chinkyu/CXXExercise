// ok. 
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
    string strWithout3a3b(int a, int b) {

        string ans;
        if (a > b) {
                while (a > b) {
                    if (a + b >= 3) {
                        ans.append("aab");
                        a -= 2;
                        b--;
                    }
                    else {
                        for (int i = 0; i < a; ++i) {
                            ans.push_back('a');
                        }
                        for (int i = 0; i < b; ++i) {
                            ans.push_back('b');
                        }
                        a = b = 0;
                    }

                }

                if (a == b && a > 0) {
                    for (int i = 0; i < b; ++i) {
                        ans.append("ab");
                    }
                    a = b = 0;
                }


        }else if(a < b) {
            while (a < b) {
                if (a + b >= 3) {
                    ans.append("bba");
                    b -= 2;
                    a--;
                }
                else {
                    for (int i = 0; i < b; ++i) {
                        ans.push_back('b');
                    }
                    for (int i = 0; i < a; ++i) {
                        ans.push_back('a');
                    }
                    a = b = 0;
                }
            }

            if (a == b && a > 0) {
                for (int i = 0; i < b; ++i) {
                    ans.append("ba");
                }
                a = b = 0;
            }

        }
        else {  // a == b 
            if (a > 0) {
                for (int i = 0; i < b; ++i) {
                    ans.append("ab");
                }
                a = b = 0;
            }
        }

        return ans;
    }
};

int main() {
    char c;
    //vector<vector<int>> n = { { -2, -2, 1, 1},{2, 2, 4, 6} };
    vector<vector<int>> n = { { 1, 1, 5, 5} };

    Solution sol;

    cout << sol.compareVersion("1.0.1", "1");

    cin >> c;
}
