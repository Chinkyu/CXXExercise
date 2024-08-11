// ¥‰∫√¿Ω : vector and unordered_map
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

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        auto result = m.find(val) == m.end();

        m[val].push_back(nums.size());
        nums.push_back(pair<int, int>(val, m[val].size() - 1));

        return result;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto result = m.find(val) != m.end();
        if (result)
        {
            auto last = nums.back();
            m[last.first][last.second] = m[val].back();
            nums[m[val].back()] = last;
            m[val].pop_back();
            if (m[val].empty()) m.erase(val);
            nums.pop_back();
        }
        return result;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
private:
    vector<pair<int, int>> nums;
    unordered_map<int, vector<int>> m;
};


class _RandomizedCollection {
public:
    multiset<int> ms;

    RandomizedCollection() {
        ms.clear();
    }

    bool insert(int val) {
        bool rtn = false;

        if (ms.find(val) == ms.end()) rtn = true;
        else rtn = false;

        ms.insert(val);
        return rtn;
    }

    bool remove(int val) {

        if (ms.find(val) == ms.end()) return false;

        ms.erase(ms.find(val));
        return true;
    }

    int _getRandom() {
        int sz = ms.size();
        int idx = rand() % sz;
        
        auto iter = ms.begin();
        std::advance(iter, idx);  //:: ckkang : mid value from multiset

        return *iter;
    }

    int getRandom() {

        vector<int> v;
        std::sample(ms.begin(), ms.end(), std::back_inserter(v), 1,
            std::mt19937{ std::random_device{}() });

        return v[0];
    }

};


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
