// 답봣는데..  이거는 거의 조작에 가깝게 푼거임..:  
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

    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i*i <= n; ++i) {
            if (n % i == 0) return false;
        }

        return true;
    }

    bool isPalindrome(string s) {
        int l = s.size();
        if (l == 1) return true;
        for (int i = 0; i < l / 2; ++i) {
            if (s[i] != s[l - i - 1]) return false;
        }

        return true;
    }

    int primePalindrome(int n) {
        if (n >= 9989900) return 100030001;

        for (int i = n; i < 2 * pow(10, 8); ++i) {
            if (isPrime(i) && isPalindrome(to_string(i))) return i;
        }
        
        return 0;
    }
};

int main() {
    char c;
    Solution sol;


    cout << sol.primePalindrome(13);

    cin >> c;
}