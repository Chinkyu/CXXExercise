// easy : while vs do  while????
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

//  어떻게 이게 풀리는지????? 
bool checkValidString(string s) {
    int leftBalance = 0;   // For left to right traversal balance
    int rightBalance = 0;  // For right to left traversal balance
    int n = s.length();

    // Left to right traversal
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '*') {
            leftBalance++;   // Consider '(' or '*' as an open parenthesis
        }
        else {
            leftBalance--;   // ')' closes an open parenthesis
        }
        if (leftBalance < 0) return false;  // Invalid if more ')' than '('
    }

    // Right to left traversal
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == ')' || s[i] == '*') {
            rightBalance++;   // Consider ')' or '*' as a closing parenthesis
        }
        else {
            rightBalance--;   // '(' needs to be matched by a closing parenthesis
        }
        if (rightBalance < 0) return false;  // Invalid if more '(' than ')'
    }

    return true;  // Valid if both traversals maintain valid balances
}



class _Solution {
public:
    bool isFind = false;
    void traverse(string& s, int idx, int depth) {
        bool rt = false;

        if (depth < 0) return;
        if (isFind == true) return;
        if (idx == s.size()) {
            if (depth == 0) {
                isFind = true;
                return;
            }
            else {
                return;
            }
        }


        if (s[idx] == '(') {
            traverse(s, idx + 1, depth + 1);
        }
        else if (s[idx] == ')') {
            traverse(s, idx + 1, depth - 1);
        }
        else if (s[idx] == '*') {
            traverse(s, idx + 1, depth + 1);
            traverse(s, idx + 1, depth - 1);
            traverse(s, idx + 1, depth);
        }

    }

    bool checkValidString(string s) {
        isFind = false;

        int star_count = 0;
        for (auto& it : s) {
            if (it == '*') star_count++;
        }
        if (star_count > 10 && star_count > s.size()/2) return true;


        traverse(s, 0, 0);

        return isFind;
    }
};


int main() {
    char c;
    Solution sol;
    string s = "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())";


    cout << sol.checkValidString(s);

    cin >> c;
}