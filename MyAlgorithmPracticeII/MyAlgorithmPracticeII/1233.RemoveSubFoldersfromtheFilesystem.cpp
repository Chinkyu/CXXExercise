// 답봤는데 : sorting을 하면 바로 앞에 것만 확인 하면 됨... !! 
// 이럴 수가... tree 쓸 필요도 없음.. 
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

// vector로는 구분이 안되네.. Tree 로 해야 되네.. 
class _Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

        sort(folder.begin(), folder.end());
        vector<string> ans;
        vector<unordered_map<string, int>> vm;

        for (auto& it : folder) {
            istringstream iss(it);
            string token;

            int i = 0;
            bool isExist = false;
            getline(iss, token, '/');  // for first /
            while (getline(iss, token, '/')) {
                if (i >= vm.size()) {
                    unordered_map<string, int> tvm;
                    tvm[token] = 1;
                    vm.push_back(tvm);
                    i++;
                    continue;
                }

                if (vm[i].find(token) != vm[i].end()) {
                    isExist = true;
                    break;
                }
                else {
                    vm[i][token] = 1;
                }

                i++;
                //std::cout << token << " ";
            }

            if (isExist == false) ans.push_back(it);
            //cout << endl;
        }

        return ans;
    }
};

struct Node{
    string v;
    unordered_map<string, Node*> m;
    Node(string s) : v(s) {}
} ;

class _Solution {
public:

    bool traverse(Node * r, vector<string> &sv, int idx) {

        if (sv.size() <= idx) return true;

        if (r->m.size() == 0) return false;

        r->m[sv[idx]] = new Node(sv[idx]);
        return traverse(r->m[sv[idx]], sv, idx + 1);
    }

    vector<string> removeSubfolders(vector<string>& folder) {
    
        sort(folder.begin(), folder.end());
        vector<string> ans;
        vector<unordered_map<string, int>> vm;

        Node* root = new Node("");

        for (auto& it : folder) {
            istringstream iss(it);
            string token;

            int i = 0;
            bool isExist = false;
            vector<string> sv;

            getline(iss, token, '/');  // for first /
            while (getline(iss, token, '/')) {
                sv.push_back(token);
            }

            if (traverse(root, sv, 0)) {
                ans.push_back(it);
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder)
    {
        sort(folder.begin(), folder.end());
        vector<string> result;
        for (string& s : folder)
            if (result.empty()                          //Check if 1. This is the first string, 
                || result.back().compare(0, result.back().length(), s, 0, result.back().length()) != 0 
                //2.parent at back is not the parent of `s` by comparing.
                || s[result.back().length()] != '/')    
                //3. If the entire parent matches `s` check if last folder name in parent does not match the folder of same depth in `s`. for cases like `/a/b, /a/bc`.
                result.push_back(s);
        return result;
    }
};

int main() {
    char c;
    Solution sol;
    vector<string> folder = { "/a", "/a/b", "/c/d", "/c/d/e", "/c/f" };

    vector<string> ans = sol.removeSubfolders(folder);
    for (auto it : ans) {
        cout << it << " ";
    }
    cin >> c;
}