// ok : map 으로 겨우... 
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

// Memory limit exceed  -> try tomorrow.... : how to do it??  
class _Solution {
    vector < pair<int, int>> v;
    int lm, ln;
public:
    Solution(int m, int n) {
        lm = m;
        ln = n;

        reset();
    }

    vector<int> flip() {
        int l = v.size();

        // 1. Seed the random number engine
        std::random_device rd;

        // 2. Initialize the Mersenne Twister engine with the seed
        std::mt19937 gen(rd());

        // 3. Define the inclusive range [0, L - 1]
        std::uniform_int_distribution<int> distrib(0, l - 1);

        // 4. Generate the random number
        int random_num = distrib(gen);

        vector<int> ans;
        ans.push_back(v[random_num].first);
        ans.push_back(v[random_num].second);
        
        v.erase(v.begin() + random_num);

        return ans;
    }

    void reset() {
        v.clear();

        for (int i = 0; i < lm; ++i) {
            for (int j = 0; j < ln; ++j) {
                v.push_back(make_pair(i, j));
            }
        }
    }
};

// timeout.. 
class _Solution {
    vector <vector<int>> v;
    int lm, ln;
public:
    Solution(int m, int n) {
        lm = m;
        ln = n;

        v = vector<vector<int>>(lm, vector<int>(ln, 0));
    }

    vector<int> flip() {

        // 1. Seed the random number engine
        std::random_device rd;

        // 2. Initialize the Mersenne Twister engine with the seed
        std::mt19937 gen(rd());

        // 3. Define the inclusive range [0, L - 1]
        std::uniform_int_distribution<int> distribm(0, lm - 1);
        std::uniform_int_distribution<int> distribn(0, ln - 1);

        // 4. Generate the random number
        int ri = distribm(gen);
        int rj = distribn(gen);


        vector<int> ans;
        if (v[ri][rj] == 0) {
            v[ri][rj] = 1;
            ans.push_back(ri);
            ans.push_back(rj);
        }
        else {
            // next 0  : from 0
            for (int i = 0; i < lm; ++i) {
                for (int j = 0; j < ln; ++j) {
                    if (v[i][j] == 0) {
                        v[i][j] = 1;
                        ans.push_back(i);
                        ans.push_back(j);
                        return ans;
                    }
                }
            }


        }

        return ans;
    }

    void reset() {
//        for (int i = 0; i < lm; ++i) {
//            for (int j = 0; j < ln; ++j) {
//                v[i][j] = 0;
//            }
//        }
        v = vector<vector<int>>(lm, vector<int>(ln, 0));
    }
};


/// <summary>
/// /  Map  으로 겨우... 
/// </summary>
class Solution {
    map<pair<int, int>, int> m;
    int lm, ln;
public:
    Solution(int m, int n) {
        lm = m;
        ln = n;

        reset();
    }

    vector<int> flip() {
        // 1. Seed the random number engine
        std::random_device rd;

        // 2. Initialize the Mersenne Twister engine with the seed
        std::mt19937 gen(rd());

        // 3. Define the inclusive range [0, L - 1]
        std::uniform_int_distribution<int> distribm(0, lm - 1);
        std::uniform_int_distribution<int> distribn(0, ln - 1);

        // 4. Generate the random number
        int ri = distribm(gen);
        int rj = distribn(gen);


        vector<int> ans;
        if (m.find(make_pair(ri, rj)) == m.end()) {
            m[make_pair(ri, rj)] = 1;
            ans.push_back(ri);
            ans.push_back(rj);
        }
        else {
            // next 0  : from 0
            for (int i = 0; i < lm; ++i) {
                for (int j = 0; j < ln; ++j) {
                    if (m.find(make_pair(i, j)) == m.end()) {
                        m[make_pair(i, j)] = 1;
                        ans.push_back(i);
                        ans.push_back(j);
                        return ans;
                    }
                }
            }


        }

        return ans;
    }

    void reset() {
        m.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */

int main() {
    char c;
    Solution sol;

    string s = "aabcb";

    cout << sol.beautySum(s);

    cin >> c;
}
