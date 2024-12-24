//  See anser
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

// trick : difficulty �� ���� �ٸ� work�� ���� �ϴ°�� ū���� ���� �ؾ� ��.. 
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

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* dfs(Node* cur, unordered_map<Node*, Node*>& mp)
    {
        vector<Node*> neighbour;
        Node* clone = new Node(cur->val);
        mp[cur] = clone;
        for (auto it : cur->neighbors)
        {
            if (mp.find(it) != mp.end())   //already clone and stored in map
            {
                neighbour.push_back(mp[it]);    //directly push back the clone node from map to neigh
            }
            else
                neighbour.push_back(dfs(it, mp));
        }
        clone->neighbors = neighbour;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;
        if (node == NULL)
            return NULL;
        if (node->neighbors.size() == 0)   //if only one node present no neighbors
        {
            Node* clone = new Node(node->val);
            return clone;
        }
        return dfs(node, mp);
    }
};

int main() {
    char c;
    Solution sol;
    vector<int> difficulty = { 66,1,28,73,53,35,45,60,100,44,59,94,27,88,7,18,83,18,72,63 };
    vector<int> profit = { 66,20,84,81,56,40,37,82,53,45,43,96,67,27,12,54,98,19,47,77 };
    vector<int> worker = { 61,33,68,38,63,45,1,10,53,23,66,70,14,51,94,18,28,78,100,16 };


    cout << sol.maxProfitAssignment(difficulty, profit, worker);

    cin >> c;
}