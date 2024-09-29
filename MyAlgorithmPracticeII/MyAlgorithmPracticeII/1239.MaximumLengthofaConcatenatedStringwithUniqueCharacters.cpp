// easy : crusion....  select and not select order... 
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
    int traverse(vector<string> &arr, int idx, vector<int> &ca) {

        if (idx == arr.size()) return 0;

        int l = arr[idx].size();

        bool can_not_add = false;
        vector<int> tca = ca;
        for (int i = 0; i < l; ++i) {
            tca[arr[idx][i] - 'a']++;
            if (tca[arr[idx][i] - 'a'] > 1) {
                can_not_add = true;
                break;
            }
        }

        vector<int> nca = ca;

        int len1 = 0;
        if (can_not_add == false) {

            // select this 
            for (int i = 0; i < l; ++i) {
                ca[arr[idx][i] - 'a']++;
            }

            len1 = traverse(arr, idx + 1, ca) + l;
        }
        // not select this
        int len2 = traverse(arr, idx + 1, nca);
        
        return (len1 > len2) ? len1 : len2;
    }

    int maxLength(vector<string>& arr) {
        vector<int> ca('z' - 'a' + 1);

        return traverse(arr, 0, ca);
    }
};

int main() {
    char c;
    Solution sol;
    //vector<string> arr = { "cha", "r", "act", "ers" };
    vector<string> arr = {
        "abcdefghijklm", "bcdefghijklmn", "cdefghijklmno", "defghijklmnop", "efghijklmnopq", "fghijklmnopqr", "ghijklmnopqrs", "hijklmnopqrst", "ijklmnopqrstu", "jklmnopqrstuv", "klmnopqrstuvw", "lmnopqrstuvwx", "mnopqrstuvwxy", "nopqrstuvwxyz", "opqrstuvwxyza", "pqrstuvwxyzab"
    };
    cout << sol.maxLength(arr);
    cin >> c;
}