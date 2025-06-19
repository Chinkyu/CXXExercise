// see answer
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
    int findNthDigit(int n)
    {
        long long digit = 9;
        int first = 1;
        int length = 1;
        while (n > digit * length)
        {
            n = n - digit * length;
            length++;
            first = first * 10;
            digit = digit * 10;
        }
        first = first + (n - 1) / length;
        string str = to_string(first);
        return str[(n - 1) % length] - '0';
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