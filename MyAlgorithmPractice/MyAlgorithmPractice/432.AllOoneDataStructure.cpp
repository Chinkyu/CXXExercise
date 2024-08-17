// ¥‰∫√¿Ω : binary logic
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

class AllOne {
public:

    void inc(string key) {

        // If the key doesn't exist, insert it with value 0.
        if (!bucketOfKey.count(key))
            bucketOfKey[key] = buckets.insert(buckets.begin(), { 0, {key} });

        // Insert the key in next bucket and update the lookup.
        auto next = bucketOfKey[key], bucket = next++;
        if (next == buckets.end() || next->value > bucket->value + 1)
            next = buckets.insert(next, { bucket->value + 1, {} });
        next->keys.insert(key);
        bucketOfKey[key] = next;

        // Remove the key from its old bucket.
        bucket->keys.erase(key);
        if (bucket->keys.empty())
            buckets.erase(bucket);
    }

    void dec(string key) {

        // If the key doesn't exist, just leave.
        if (!bucketOfKey.count(key))
            return;

        // Maybe insert the key in previous bucket and update the lookup.
        auto prev = bucketOfKey[key], bucket = prev--;
        bucketOfKey.erase(key);
        if (bucket->value > 1) {
            if (bucket == buckets.begin() || prev->value < bucket->value - 1)
                prev = buckets.insert(bucket, { bucket->value - 1, {} });
            prev->keys.insert(key);
            bucketOfKey[key] = prev;
        }

        // Remove the key from its old bucket.
        bucket->keys.erase(key);
        if (bucket->keys.empty())
            buckets.erase(bucket);
    }

    string getMaxKey() {
        return buckets.empty() ? "" : *(buckets.rbegin()->keys.begin());
    }

    string getMinKey() {
        return buckets.empty() ? "" : *(buckets.begin()->keys.begin());
    }

private:
    struct Bucket { int value; unordered_set<string> keys; };
    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> bucketOfKey;
};



class _AllOne {
public:
    unordered_map<string, int> m;
    int max_count = 0;
    string max_key = "";
    int min_count = INT_MAX;
    string min_key = "";

    AllOne() {
        m.clear();
    }

    void inc(string key) {
        m[key]++;

        if (max_count < m[key]) {
            max_key = key;
            max_count = m[key];
        }

        if (m.size() == 1) {
            max_key = key;
            max_count = m[key];
            max_key = key;
            max_count = m[key];
            return;
        }

        if (key == min_key) {
            int t_min_count = INT_MAX;
            string t_min_string = "";
            for (auto& it : m) {
                if (it.second < t_min_count) {
                    t_min_count = it.second;
                    t_min_string = it.first;
                }
            }
            min_key = t_min_string;
            min_count = t_min_count;
            return;
        }

        if (m[key] != 0 && m[key] < min_count) {
            min_key = key;
            min_count = m[key];
            return;
        }

        if (min_key == "") {
            min_key = key;
            min_count = m[key];
        }
    }

    void dec(string key) {
        m[key]--;

        if (key == max_key) {
            int t_max_count = 0;
            string t_max_string = "";
            for (auto& it : m) {
                if (it.second > t_max_count) {
                    t_max_count = it.second;
                    t_max_string = it.first;
                }
            }
            max_key = t_max_string;
            max_count = t_max_count;
        }

        if (m[key] != 0 && m[key] < min_count) {
            min_key = key;
            min_count = m[key];
        }

        if (m[key] == 0) m.erase(key);

        if (m.size() == 1) {
            max_key = key;
            max_count = m[key];
            max_key = key;
            max_count = m[key];
            return;
        }
    }

    string getMaxKey() {
        return max_key;
    }

    string getMinKey() {
        return min_key;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

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
