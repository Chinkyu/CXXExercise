// see answer : 얼텡이가 없음..  S, T 둘다 1이 하나라도 있으면 YES
//              모두 Zero 인 String 은 다른 값으로 변환이 불가능함... 

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
    bool makeStringsEqual(string s, string t) {
        return (s.find('1') != string::npos) == (t.find('1') != string::npos);
    }
};

int main() {
    char c;
    Solution sol;
    vector<string> queries = { "bbb", "cc" };
    vector<string> words = { "a", "aa", "aaa", "aaaa" };

    vector<int> ans = sol.numSmallerByFrequency(queries, words);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}