//  답봣음 :  \t \n 으로 처리해서 getline으로 못하고 token 모아야함.. 
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
    int lengthLongestPath(string input) {
        stringstream ss(input);
        string data;
        // this map will store the len upto previous dir for the current explored path 
        unordered_map<int, int>len;
        int res = 0;

        while (getline(ss, data, '\n'))
        {
            // data will contain string like dir, /tsubdir1, /tsubdir2....etc
            int numTabs = 0;   //count no of tabs

            while (data[numTabs] == '\t') numTabs++;

            if (numTabs == 0)
                len[numTabs] = data.size(); //root directory
            else {
                // length upto previous dir + len("/") + no of chars after tabs for current filename/ dirname
                len[numTabs] = len[numTabs - 1] + 1 + data.substr(numTabs).size();   // added 1 for '/'
            }

            // If it's a file then update the res 
            if (data.find('.') != string::npos)
                res = max(res, len[numTabs]);
        }

        return res;
    }
};

class _Solution {
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
        string token;

        int depth = 0;
        int max_lengh = 0;
        //getline(iss, token, '/');  // for first /

        while (getline(iss, token, '\\')) {

            if (token == "t") {
                depth++;
            }
            else if (token == "n") {
                depth = 0;
            }

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
    string input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";


    vector<int> ans = sol.getStrongest(arr, 2);

    for (auto it : ans) {
        cout << it << " ";
    }

    cin >> c;
}