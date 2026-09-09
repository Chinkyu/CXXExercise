// ok : simply..   restriction checking... 
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
    unordered_map<string, string> m;
    long long l = 0;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        
        //if (m.find(longUrl) != m.end()) {
        //    return m[longUrl];
       /// }

        string s = "http://tinyurl.com/" + to_string(++l);
        m[s] = longUrl;
        return s;

    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return  m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

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
