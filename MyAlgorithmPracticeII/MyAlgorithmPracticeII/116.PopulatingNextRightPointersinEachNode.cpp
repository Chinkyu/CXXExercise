// ok 
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <stack>
#include <bitset>
#include <set>
#include <list>
#include <cmath>
#include <regex>
#include <memory>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {

        vector<Node*> v;
        v.push_back(root);

        if (root == nullptr) return root;
        root->next = nullptr;
        do {
            vector<Node*> tv;
            for (auto& it : v) {
                if (it->left != nullptr) tv.push_back(it->left);
                if (it->right != nullptr) tv.push_back(it->right);
            }

            if (tv.size() == 0) break;

            for (int i = 0; i < tv.size() - 1; ++i) {
                tv[i]->next = tv[i + 1];
            }
            tv.back()->next = nullptr;
            v = tv;
        } while (v.size() != 0);

        return root;
    }
};

int main() {
    char c;
    Solution sol;
    vector<vector<string>> orders = { {"David", "3", "Ceviche"}, {"Corina", "10", "Beef Burrito"}, {"David", "3", "Fried Chicken"}, {"Carla", "5", "Water"}, {"Carla", "5", "Ceviche"}, {"Rous", "3", "Ceviche"} };

    vector<vector<string>> ans = sol.displayTable(orders);

    for (auto& it : ans) {
        for (auto& jt : it) {
            cout << jt << " ";
        }
    }

    std::cin >> c;
}