// refer answer : 그냥 앞에서 하면 됨... 
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


//이거를 앞에서 부터 하면 된다는데.. 진짜... 신기한데... 안될거 같은데....... 희얀하네...
// 어짜피 중복이 안되니까. 한가지 밖에 없는건가?????
class Solution {
public:
    int maxSubstrings(string word) {
        int l = word.size();
        unordered_map<char, int> m;

        int ans = 0;
        for (int i = 0; i < l; ++i) {
            if (m.find(word[i]) != m.end() && i - m[word[i]] >= 3) {  // if exist
                ans++;
                m.clear();
            }
            else {
                if (m.find(word[i]) == m.end()) m[word[i]] = i;
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    string word = "aaaeaaa";

    cout << sol.maxSubstrings(word);

    cin >> c;
}