// Ok. : Tricky in debuggin g.. 
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
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {

        unordered_map<Node*, int> vm;

        if (head == nullptr) return nullptr;


        Node* p = head;
        int i = 0;
        while (p != nullptr) {
            vm[p] = i;
            p = p->next;
            i++;
        }

        int l = i;
        vector<int> v(l, -1);

        // find index
        i = 0;
        p = head;
        while (p != nullptr) {
            if (p->random != nullptr) {
                v[i] = vm[p->random];
            }
            p = p->next;
            i++;
        }

        // copy
        p = head;
        i = 0;
        vector<Node*> nv(l, nullptr);


        Node* nHead = new Node(p->val);
        Node* np = nHead;
        nv[i++] = np;
        p = p->next;
        while (p != nullptr) {
            np->next = new Node(p->val);
            nv[i++] = np->next;
            np = np->next;
            p = p->next;
        }

        // put random
        np = nHead;
        i = 0;
        while (np != nullptr) {
            if (v[i] != -1) {
                np->random = nv[v[i]];
            }
            else {
                np->random = nullptr;
            }
            np = np->next;
            i++;
        }

        return nHead;
    }
};

int main() {
    char c;
    Solution sol;

    Node* root = new Node(3);
    root->next = new Node(3);
    Node* p = root->next;

    Node* q = p;
    p->next = new Node(3);
    q = p->next;

    p->random = root;

    cout << sol.copyRandomList(root);
    cin >> c;
}