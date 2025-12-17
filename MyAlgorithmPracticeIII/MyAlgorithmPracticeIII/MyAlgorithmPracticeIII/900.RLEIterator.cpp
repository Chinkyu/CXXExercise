// tricky for debugging : but its ok... 
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

#if 0
class RLEIterator {
public:
    vector<int> d;
    int idx = -1;
    RLEIterator(vector<int>& encoding) {
        int l = encoding.size();
        d.clear();
        idx = -1;

        for (int i = 0; i < l; i += 2) {
            for (int j = 0; j < encoding[i]; ++j) {
                d.push_back(encoding[i + 1]);
            }
        }
    }

    int next(int n) {
        int l = d.size();

        idx += n;
        if (idx < l) {
            return d[idx];
        }
        else {
            return -1;
        }

    }
};
#endif 

class RLEIterator {
public:
    vector<int> en;
    int idx = 0;
    int remain = 0;
    RLEIterator(vector<int>& encoding) {
        idx = 0;
        remain = encoding[0];

        en = encoding;
    }

    int next(int n) {
        int l = en.size();
        remain -= n;

        if (idx >= l) return -1;

        while (en[idx] == 0 || remain < 0) {
            idx += 2;
            if (idx >= l) return -1;
            remain += en[idx];
        }

        int ans = en[idx + 1];
        if (remain == 0) idx += 2;
        return ans;
    }
};



/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */

int main() {
    char c;
    
    vector<int> encoding = { 3, 8, 0, 9, 2, 5 };

    RLEIterator* obj = new RLEIterator(encoding);
    cout << obj->next(2) << " ";
    cout << obj->next(1) << " ";
    cout << obj->next(1) << " ";
    cout << obj->next(2) << " ";

    cin >> c;
}
