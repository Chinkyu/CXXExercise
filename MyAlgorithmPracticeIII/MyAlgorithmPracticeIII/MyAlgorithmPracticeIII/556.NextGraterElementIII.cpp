// ok : 뒤에서 앞으로 커지다가 작어지면 작아지는것보다 하나큰것 하고 바꾼뒤에 Assending 으로 Sort 하기
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
#include <chrono>
#include <iterator>

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int l = str.size();

        int pre = -1;
        for (int i = l - 1; i >= 0; --i) {
            if (str[i] >= pre) {
                pre = str[i];
                if (i == 0) return -1;
                continue;
            }

            // not big then next 

            // find next max and swap
            int next_max = INT_MAX;
            int next_max_idx = i;
            for (int j = i + 1; j < l; ++j) {
                if (str[j] > str[i] && str[j] < next_max) {
                    next_max = str[j];
                    next_max_idx = j;
                }
            }

            swap(str[i], str[next_max_idx]);
            sort(str.begin() + i + 1, str.end());
            break;
        }

        auto ans = stoll(str);

        if (ans > INT_MAX) {
            return -1;
        }

        return ans;
    }
};


int main() {
    char c;
    Solution sol;


    cout << sol.nextGreaterElement(12);


    cin >> c;
}
