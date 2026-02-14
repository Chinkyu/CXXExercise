// ok trickey debugging : might be better way. 
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
    string validIPAddress(string queryIP) {
        stringstream ss(queryIP);
        string token;

        if (queryIP.find(".", 0) != string::npos) {
            for (int i = 0; i < 3; ++i) {
                token = "";
                getline(ss, token, '.');
                
                if ((token[0] == '0' && token.size() > 1) || token.size() > 3 || token.size() == 0) return "Neither";
                for (auto& it : token) {
                    if ((it < '0' || '9' < it)) {
                        return "Neither";
                    }
                }
                int n = stoi(token);
                if (n < 0 || 255 < n) return "Neither";
            }

            token = "";
            getline(ss, token);
            if ((token[0] == '0' && token.size() > 1) || token.size() > 3 || token.size() == 0) return "Neither";
            for (auto& it : token) {
                if ((it < '0' || '9' < it)) {
                    return "Neither";
                }
            }
            int n = stoi(token);
            if (n < 0 || 255 < n) return "Neither";

            return "IPv4";
        }
        else {
            for (int i = 0; i < 7; ++i) {
                token = "";
                getline(ss, token, ':');

                if (/*(token[0] == '0' && token.size() != 1) || */token.size() > 4 || token.size() == 0) return "Neither";
                for (auto& it : token) {
                    if ((it < '0' || '9' < it) && (it < 'a' || 'f' < it) && (it < 'A' || 'F' < it)) {
                        return "Neither";
                    }
                }
            }

            token = "";
            getline(ss, token);
            if (/*(token[0] == '0' && token.size() != 1) || */ token.size() > 4 || token.size() == 0) return "Neither";
            for (auto& it : token) {
                if ((it < '0' || '9' < it) && (it < 'a' || 'f' < it) && (it < 'A' || 'F' < it)) {
                    return "Neither";
                }
            }
            return "IPv6";
        }

        return "Neither";
    }
};

int main() {
    char c;
    Solution sol;

    string addr = "172.16.254";
    // "1e1.4.5.6";
    //"2001:0db8:85a3:0:0:8A2E:0370:7334";

    cout << sol.validIPAddress(addr);

    cin >> c;
}
