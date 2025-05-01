//  see answer : xor of all number solve it. 
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


/*
Pattern 8-> Decode XORed Array.
In This type of Problems generally you have given a array and based on props of xor
You have to decode original array
Generally taking xor off all element give you answer or same time us prop of a^a==0
or A^B=c then A=B^c
Questions

Decode-xored-permutation
Decode-xored-array
Find-xor-beauty-of-array
find-the-original-array-of-prefix-xor
*/
//JUST XOR EVERY ELEMENT
class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int xorr = 0;
        for (auto it : nums) {
            xorr ^= it;
        }
        return xorr;
    }
};


int main() {
    char c;
    Solution sol;

    string s = "aabcbbca";

    cout << sol.lastNonEmptyString(s);

    cin >> c;
}