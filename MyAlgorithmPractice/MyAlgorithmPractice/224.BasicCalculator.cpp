// ¥‰∫√¿Ω... : sliding windows
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
    int calculate(string s) {
        long long int sum = 0;
        int sign = 1;
        stack<pair<int, int>> st;

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                long long int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                sum += num * sign;
                sign = 1;
            }
            else if (s[i] == '(') {
                st.push({ sum, sign });
                sum = 0;
                sign = 1;
            }
            else if (s[i] == ')') {
                sum = st.top().first + (st.top().second * sum);
                st.pop();

            }
            else if (s[i] == '-') {
                sign = -1 * sign;
            }
        }
        return sum;
    }
};

int main() {
    Solution sol;
    char c;

    //	vector<vector<char>> mat =
    //	{
    //			{'o', 'a', 'a', 'n'},
    //			{'e', 't', 'a', 'e'},
    //			{'i', 'h', 'k', 'r'},
    //			{'i', 'f', 'l', 'v'}
    //	};

    //	vector<string> words = { "oath", "pea", "eat", "rain" };

    vector<vector<char>> mat =
    {
            {'a', 'b'},
            {'c', 'd'}
    };

    vector<string> words = { "ab", "cb", "ad", "bd", "ac", "ca", "da", "bc", "db", "adcb", "dabc", "abb", "acb" };
    //vector<string> words = { "ac", "ca", "db" };


    vector<string> ans = sol.findWords(mat, words);
    for (auto it : ans) {
        cout << it.c_str() << endl;
    }

    cin >> c;
}
