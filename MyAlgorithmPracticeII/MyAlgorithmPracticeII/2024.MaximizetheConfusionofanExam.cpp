// ok : sliding window with little tricky debugging 
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <stack>
#include <bitset>
#include <set>
#include <list>
#include <cmath>
#include <regex>
#include <memory>

using namespace std;

// sliding window
class Solution {
public:

    bool isMaxExam(vector<int>& v, int k) {
        if (v[0] > k && v[1] > k) return false;
        return true;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        int l = answerKey.size();

        // first sliding window  other is k
        int st = 0, ed = 0;
        vector<int> v(2, 0);
        if (answerKey[ed] == 'T') v[1]++; else v[0]++;
        while (isMaxExam(v, k) == true && ed < l) {
            if (ed >= l) break; else ed++;
            if (answerKey[ed] == 'T') v[1]++; else v[0]++;
        } 

        int ans = ed - st;

        for (int i = 1; i < l - 1; ++i) {
            // remove i - 1;
            if (answerKey[i - 1] == 'T') v[1]--; else v[0]--;
            st = i;
            while (isMaxExam(v, k) == true && ed < l) {
                if (ed >= l) break; else ed++;
                if (answerKey[ed] == 'T') v[1]++; else v[0]++;
            }

            ans = max(ans, ed - st);
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    string answerKey = "FFFTTFTTFT";

    std::cout << sol.maxConsecutiveAnswers(answerKey, 3);
    std::cin >> c;
}