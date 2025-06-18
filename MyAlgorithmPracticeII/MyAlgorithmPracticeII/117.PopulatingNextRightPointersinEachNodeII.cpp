// input 이 좀 이상한것 같다.. !!!!! - skip
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
        vector<Node*> n1, n2;

        n1.push_back(root);

        do {
            for (int i = 0; i < n1.size() - 1; ++i) {
                n1[i]->next = n1[i + 1];
            }

            vector<Node*> n2;
            for (int i = 0; i < n1.size(); ++i) {
                if (n1[i]->left != nullptr) n2.push_back(n1[i]->left);
                if (n1[i]->right != nullptr) n2.push_back(n1[i]->right);
            }
            n1.clear();
            n1 = n2;
        } while (n1.size() > 1);

        return root;
    }
};

int main() {
    char c;
    Solution sol;

    Node* root = new Node(1);

    root->left = new Node(2);


    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right = new Node(3);
    root->right->right = new Node(7);

    cout << sol.connect(root);

    cin >> c;
}