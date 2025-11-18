// ok : some try and error 
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

class _Solution {
public:
    string decodeString(string s) {
        stringstream ss(s);

        string token;
        string ans;


        while (getline(ss, token, '[')) {
            int num = stoi(token);
            getline(ss, token, ']');
            for (int i = 0; i < num; ++i) {
                ans += token;
            }

            int pk = ss.peek();
            while (pk != EOF && !isdigit(pk)) {
                char c;
                ss >> c;
                ans.push_back(c);

                pk = ss.peek();
            }
        }
        return ans;
    }
};

// recursive... -> tomorrow 
class Solution {
public:

    bool exchange(string& s, int &idx) {

        string ts = s;
        int st = idx;
        while (ts[st] != '[') st--;
        int md = st;
        string str = ts.substr(st + 1, idx - st - 1);

        st--;
        while (st >= 0 && isdigit(ts[st])) st--;
        if (st == 0) st = -1;
        int num = stoi(ts.substr(st + 1, md - st - 1));
        
        string swaped;
        for (int i = 0; i < num; ++i) {
            swaped.append(str);
        }


        s = ts.substr(0, st + 1);
        s.append(swaped);
        if(ts.size() > idx + 1) s.append(ts.substr(idx + 1));

        idx = st;
        return true;
    }


    string decodeString(string s) {
        stringstream ss(s);

        string token;
        string ans;

        int l = s.size();

        for (int i = 0; i < l; ++i) {

            if (s[i] == ']') {
                exchange(s, i);
                l = s.size();
            }
        }

        return s;
    }
};

int main() {
    char c;
    Solution sol;
    //string s = "2[abc]3[cd]ef3[cd]";
    //string s = "2[abc]zzzz";
    string s = "3[a2[c]]";

    //cout << sol.exchange(s, 5);
    cout << sol.decodeString(s);


    //cout << "Test  application";

    cin >> c;
}
