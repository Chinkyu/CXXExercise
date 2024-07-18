// ¥‰∫√¿Ω... : kmp
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
    void computelps(vector<int>& lps, string s, int m)
    {
        int len = 0, i = 1;
        while (i < m)
        {
            if (s[len] == s[i])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0) len = lps[len - 1];
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        int n = s.size();
        string ans = s;
        s += '#';

        for (int i = n - 1; i >= 0; i--)
        {
            s += s[i];
        }
        vector<int>lps(2 * n + 2, 0);
        computelps(lps, s, n + n + 1);
        string temp = "";
        for (int i = n - 1; i >= lps[2 * n]; i--)
        {
            temp += s[i];
        }
        return temp + ans;
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
