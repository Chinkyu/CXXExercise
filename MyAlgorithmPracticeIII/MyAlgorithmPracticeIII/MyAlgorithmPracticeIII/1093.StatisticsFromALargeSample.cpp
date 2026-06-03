// ok.....  find ith element....   odd + 1, even 
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

    void getith(vector<int>& count, int idx, int& m1, int& m2) {
        int l = count.size();

        int accu = 0;
        bool m1_choose = false, m2_choose = false;
        for (int i = 0; i < l; ++i) {
            accu += count[i];
            if (m1_choose == false && accu >= idx) {
                m1 = i;
                m1_choose = true;
            }
            if (m2_choose == false && accu >= idx + 1) {
                m2 = i;
                m2_choose = true;
            }

            if (m1_choose == true && m2_choose == true) break;

        }
    }

    vector<double> sampleStats(vector<int>& count) {
        int l = count.size();

        long long sum = 0;
        long long num = 0;
        int first = -1, last = -1, mod = -1;
        int maccur = 0;
        for (int i = 0; i < l; ++i) {
            sum += count[i] * (long long)i;
            num += count[i];

            if (first == -1 && count[i] != 0) first = i;
            if (count[i] != 0) last = i;

            if (count[i] > maccur) {
                maccur = count[i];
                mod = i;
            }
        }

        int m1, m2;
        double mid = 0;
        if (num % 2 == 1) {
            getith(count, num / 2 + 1, m1, m2); // odd case + 1
            mid = m1;
        }
        else {
            getith(count, num / 2 , m1, m2);
            mid = (m1 + m2) / (double)2;
        }

        vector<double> ans;
        ans.push_back(first);
        ans.push_back(last);
        ans.push_back(sum / (double)num);
        ans.push_back(mid);
        ans.push_back(mod);

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> count = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

    vector<double> ans = sol.sampleStats(count);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
