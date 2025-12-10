// may be bad implementation 
//   
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
#include <random>

using namespace std;

class RandomizedSet {
public:
    map<int, int> v;
    RandomizedSet() {
        v.clear();
    }

    bool insert(int val) {
        if (v.find(val) != v.end()) return false;
        v[val] = 1;
        return true;
    }

    bool remove(int val) {
        if (v.find(val) != v.end()) {
            v.erase(val);
            return true;
        }
        return false;
    }

    int getRandom() {
        int l = v.size();
        auto it = v.begin();

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, l - 1);
        int random_number = distrib(gen);

        std::advance(it, random_number);
        return it->first;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 0, 3, 2, 1 };

    cout << sol.sortPermutation(nums);

    cin >> c;
}
