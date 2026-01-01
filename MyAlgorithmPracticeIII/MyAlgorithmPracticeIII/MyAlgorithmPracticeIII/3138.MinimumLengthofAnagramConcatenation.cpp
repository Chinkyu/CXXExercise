// tricky in debugging 

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
    int minAnagramLength(string s) {
        unordered_map<char, int> m;

        for (auto& it : s) {
            m[it]++;
        }

        int num = INT_MAX;
        long long sum = 0;
        for (auto& it : m) {
            num = min(num, it.second);
            sum += it.second;
        }

        int unit = sum / num;
        int m_size = m.size();


        for (int i = num; i >= 1; --i) {
            unordered_map<char, int> cmp = m;
            for (auto& it : cmp) {
                it.second /= i;
            }

            bool reduce_num = false;

            for (int k = 0; k < s.size(); k += sum/i) {
                // check by comparing unit
                unordered_map<char, int> m1;
                for (int j = k; j < k + sum/i; ++j) {
                    m1[s[j]]++;
                }
                if (m1 != cmp) {
                    reduce_num = true;
                    break;
                }

            }

            if (reduce_num == false) return sum / i;
        }


        return sum;
    }
};

int main() {
    char c;
    Solution sol;

    string s = "abcbcacabbaccba";

    cout << sol.minAnagramLength(s);

    cin >> c;
}
