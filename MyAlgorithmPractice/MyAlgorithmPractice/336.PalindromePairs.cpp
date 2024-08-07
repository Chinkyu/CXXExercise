// ¥‰∫√¿Ω : math
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
    // kind of like a dp map, which stores if the calculated string is a palindrome or not
    unordered_map<string, bool> check;
    // function to check is string is palindrome
    bool palin(string& s)
    {
        if (check.find(s) != check.end())
            return check[s];

        if (s.length() == 0) {
            check[s] = true;
            return true;
        }
        int n = s.length();
        for (int i = 0; i <= n / 2; i++)
        {
            if (s[i] != s[(n - i) - 1])
            {
                check[s] = false;
                return false;
            }
        }
        check[s] = true;
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {

        unordered_map<string, int> mp;
        vector<vector<int>> ans;
        //storing the reverse of every string in unordered map
        for (int i = 0; i < words.size(); i++)
        {
            string str = words[i];
            reverse(str.begin(), str.end());
            mp[str] = i;
        }
        // if any string is "" means palindrome strings and "" string will form a pair
        if (mp.find("") != mp.end())
        {
            for (int i = 0; i < words.size(); i++)
            {
                if (i == mp[""])
                    continue;
                if (palin(words[i]))
                {
                    ans.push_back({ i, mp[""] });
                }
            }
        }
        // checking in the main vector
        for (int i = 0; i < words.size(); i++)
        {
            // storing the ith word in right and left as ""
            string right = words[i];
            string left = "";
            // we will delete letters from right and insert each letter, character by character in left and check if it is present in the map or not. If present, it should not have the same index as i.

            // if all these conditions pass, then we can push the indexes in our answer vector
            for (int j = 0; j < words[i].length(); j++)
            {
                left.push_back(words[i][j]);
                right.erase(right.begin() + 0);
                if (mp.find(left) != mp.end() and palin(right) and mp[left] != i)
                    ans.push_back({ i, mp[left] });

                if (mp.find(right) != mp.end() and palin(left) and mp[right] != i)
                    ans.push_back({ mp[right], i });
            }
        }
        // return ans;
        return ans;
    }
};

//UPVOTE IF YOU LIKED THE ANSWER..THANK YOU

int main() {
    Codec sol;
    char c;

    TreeNode* r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->right = new TreeNode(3);
    r->right->left = new TreeNode(4);
    r->right->right = new TreeNode(5);


    string ans = sol.serialize(r);
    cout << ans;

    TreeNode* root = sol.deserialize(ans);

    cin >> c;
}
