//  ok
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
#include <set>
#include <list>
#include <regex>
#include <memory>
#include <functional>

using namespace std;

class Solution {
public:

    bool isFile(string& s) {

        for (auto it : s) {
            if (it == '.') return true;
        }
        return false;
    }

    int lengthLongestPath(string input) {

        unordered_map<int, string> path;

        istringstream iss(input);
        string line;
        string token;

        //int depth = 0;
        int max_lengh = 0;
        //getline(iss, token, '/');  // for first /

        while (getline(iss, line, '\n')) {

            int depth = 0;
            int idx = 0;
            while (line[idx] == '\t') {
                depth++;
                idx++;
            }

            token = line.substr(idx);
            if (isFile(token)) {
                int pl = 0;
                for (int i = 0; i < depth; ++i) {
                    pl += path[i].size() + 1; // adding '\'
                }
                pl += token.size();

                max_lengh = max(max_lengh, pl);
            }
            else {
                path[depth] = token;
            }
        }

        return max_lengh;
    }
};

int main() {
    char c;
    Solution sol;
    string input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"; 
    //"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";


    cout << sol.lengthLongestPath(input);

    cin >> c;
}