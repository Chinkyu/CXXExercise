//  답봤음 : 잘이해안감
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

using namespace std;

class Solution {

public:

    long long wonderfulSubstrings(string word) {

        unordered_map<int, int> count;

        int mask = 0;

        count[0] = 1;

        long long result = 0;

        for (char c : word) {

            mask ^= 1 << (c - 'a');

            result += count[mask];

            for (int i = 0; i < 10; i++) {

                result += count[mask ^ (1 << i)];

            }

            count[mask]++;

        }

        return result;

    }

};


// timeout
class _Solution {

public:

    long long wonderfulSubstrings(string word) {
        int l = word.size();
        vector<int> ac(l+1, 0);

        for (int i = 1; i <= l; ++i) {
            int c = word[i-1] - 'a';
            ac[i] = ac[i - 1];
            ac[i] ^= 0x01 << c;
        }

        long long ans = l;

        for (int i = 0; i <= l - 2; ++i) {
            for (int j = i + 2; j <= l; ++j) {
                int dif = ac[i] ^ ac[j];
                if (dif == 0 ||
                        dif == 1 || dif == 2 || dif == 4 || dif == 8 ||
                        dif == 16 || dif == 32 || dif == 64 || dif == 128 ||
                        dif == 256 || dif == 512) ans++;
                    /*
                    int oneCount = 0;
                    for (int k = 0; k < 10; k++) {
                        oneCount += dif & 0x1;
                        dif >>= 1;
                        if (oneCount > 1) break;
                    }

                    if (oneCount == 1) ans++;
                    */
            }
        }

        return ans;
    }

};

int main() {
    char c;
    Solution sol;

    string word = "aabb";

    cout << sol.wonderfulSubstrings(word);

    cin >> c;
}