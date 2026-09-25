// ok : // sub string  이라 위에서 아래서 한턴만 바구기... 크면...
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


// sub string  이라 위에서 아래서 한턴만 바구기... 크면... 
class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int l = num.size();

        bool isSwitch = false;
        for (int i = 0; i < l; ++i) {

            if (num[i] < change[num[i]-'0'] + '0') {
                if (isSwitch == false) {
                    isSwitch = true;
                }
                num[i] = change[num[i]-'0'] + '0';
            }
            else if (num[i] > change[num[i]-'0'] + '0') {
                if (isSwitch == true) {
                    break;
                }
            }
        }

        return num;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 4, -2, -3, 4, 1 };
    cout << sol.subArrayRanges(nums);

    cin >> c;
}
