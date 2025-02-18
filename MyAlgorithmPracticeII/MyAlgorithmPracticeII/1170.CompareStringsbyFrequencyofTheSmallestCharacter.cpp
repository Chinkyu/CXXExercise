// easy : multiset's lower_bound  and  distance 를 사용 하면 간단하게 해결됨... 

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

    int f(string& s) {
        map<char, int> m;

        for (auto& it : s) {
            m[it]++;
        }

        return m.begin()->second;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {

        multiset<int> ms;
        //map<int, int> m;
        vector<int> ans;

        for (auto& it : words) {
            int n = f(it);
            ms.insert(n);
            //m[n]++;
        }

#if 0
        vector<int> nv;
        for (auto& it : m) {
            nv.push_back(it.first);
        }

        sort(nv.begin(), nv.end());
#endif 

        for (int i = 0; i < queries.size(); ++i) {
            auto lb = ms.lower_bound( f(queries[i]) + 1); // one more 
            int num = distance(lb, ms.end());
            ans.push_back(num);
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<string> queries = { "bbb", "cc"};
    vector<string> words = { "a", "aa", "aaa", "aaaa" };

    vector<int> ans = sol.numSmallerByFrequency(queries, words);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}