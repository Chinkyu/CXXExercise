// OK :  Good it doesn't have multiple instance
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

class AuthenticationManager {
public:
    unordered_map<string, vector<int>> m;
    int ttl = 0;
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }

    void generate(string tokenId, int currentTime) {
        vector<int> v = { currentTime, currentTime + ttl };
        m[tokenId] = v;
    }

    void renew(string tokenId, int currentTime) {
        if (m.find(tokenId) == m.end()) return;
        if (m[tokenId][0] <= currentTime && currentTime < m[tokenId][1]) {
            m[tokenId][1] = currentTime + ttl;
        }
    }

    int countUnexpiredTokens(int currentTime) {
        int cnt = 0;
        for (auto& it : m) {
            if (it.second[0] <= currentTime && currentTime < it.second[1]) cnt++;
        }

        return cnt;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */

int main() {
    char c;
    AuthenticationManager sol(5);

    sol.renew("aaa", 1);
    sol.generate("aaa", 2);
    cout << sol.countUnexpiredTokens(6);

    sol.generate("bbb", 7);
    sol.renew("aaa", 8);
    sol.renew("aaa", 10);
    cout << sol.countUnexpiredTokens(15);




    cin >> c;
}