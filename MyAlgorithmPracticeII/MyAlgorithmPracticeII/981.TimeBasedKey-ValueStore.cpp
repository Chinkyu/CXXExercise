// get hit from anwer
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
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
    string get(string key, int timestamp) {
        auto it = m[key].upper_bound(timestamp);
        return it == m[key].begin() ? "" : prev(it)->second;
    }


=> lower_bound를 가지고 하는것 보다..   Upper_bound 를 가지고 하는것이 훨씬 쉽고 간단하다….
*/

class TimeMap {
public:
    map<string, map<int, string>> m;
    TimeMap() {
        m.clear();
    }

    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }

    string _get(string key, int timestamp) {
        map<int, string> sm = m[key];
        
        if (sm.size() == 0) return "";

        auto lb = sm.lower_bound(timestamp);

        if (lb == sm.end()) {
            return prev(lb)->second;
        }

        if (timestamp < lb->first) {
            if (lb == sm.begin()) return "";
            return prev(lb)->second;
        }
        return lb->second;

    }

    string get(string key, int timestamp) {
        auto it = m[key].upper_bound(timestamp);
        return it == m[key].begin() ? "" : prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main() {
    TimeMap sol;
    char c;

    sol.set("foo", "bar", 1);
    cout << sol.get("foo", 1);
    cout << sol.get("foo", 3);

    cin >> c;
}
