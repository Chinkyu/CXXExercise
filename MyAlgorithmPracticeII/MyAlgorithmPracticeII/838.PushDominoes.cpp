// Tricky.. : State machine and put 'R' at the end 
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
    enum {
        s0,
        s1,
        s2,
        s3,
        s4
    };

    string pushDominoes(string dominoes) {
        int l = dominoes.size();
        string ans = dominoes;
        int pi = 0;
        int s = s0;

        // set right put 'R'
        dominoes.push_back('R');
//        for (int i = l - 1; i >= 0; --i) {
//           if (dominoes[i] == 'L') {
//                dominoes.push_back('R');
//                break;
//            }
//            else {
//                dominoes.push_back('L');
//                break;
//            }
//        }

        for (int i = 0; i <= l; ++i) {
            if (dominoes[i] == '.') continue;
            switch (s) {
            case s0:
                if (dominoes[i] == 'L') {
                    s = s1;
                }
                else { // R
                    s = s2;
                }
                break;
            case s1:
                if (dominoes[i] == 'L') {
                    s = s1;
                }
                else { // R
                    s = s2;
                }
                break;
            case s2:
                if (dominoes[i] == 'L') {
                    s = s3;
                }
                else { // R
                    s = s4;
                }
                break;
            case s3:
                if (dominoes[i] == 'L') {
                    s = s1;
                }
                else { // R
                    s = s2;
                }
                break;
            case s4:
                if (dominoes[i] == 'L') {
                    s = s3;
                }
                else { // R
                    s = s4;
                }
                break;
            }

            // handling 
            switch (s) {
                case s1:
                    // L from pi to now
                    for (int j = pi; j < i; ++j) ans[j] = 'L';
                    pi = i + 1;
                    break;
                case s2:
                    // no actin
                    pi = i + 1;
                    break;
                case s3:

                    for (int j = 0; j < (i - pi) / 2; ++j) {
                        ans[pi + j] = 'R';
                        ans[i - 1 - j] = 'L';
                    }
                    pi = i + 1;
                    break;
                case s4:
                    // R from pi to now
                    for (int j = pi; j < i; ++j) ans[j] = 'R';
                    pi = i + 1;
                    break;
            }
        }
        
        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    //string dominoes = "RR.L";
    string dominoes = ".L.R...LR..L..";
    //string dominoes = ".L.R.";
    cout << sol.pushDominoes(dominoes);

    cin >> c;
}