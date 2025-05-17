// see hint : do not actually flip.. just count flip_count
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

// timeout 
class _Bitset {
public:
    vector<int> v;
    int cnt = 0;
    int l = 0;
    _Bitset(int size) {
        v = vector<int>(size, 0);
        cnt = 0;
        l = size;
    }

    void fix(int idx) {
        if (v[idx] == 0) {
            cnt++;
            v[idx] = 1;
        }
    }

    void unfix(int idx) {
        if (v[idx] == 1) {
            cnt--;
            v[idx] = 0;
        }
    }

    void flip() {

        for (int i = 0; i < l; ++i) {
            if (v[i] == 1) {
                cnt--;
                v[i] = 0;
            }
            else {
                cnt++;
                v[i] = 1;
            }
        }
    }

    bool all() {
        return l == cnt;
    }

    bool one() {
        return cnt >= 1;
    }

    int count() {
        return cnt;
    }

    string toString() {
        string s;
        for (int i = 0; i < l; ++i) {
            s.push_back(v[i] + '0');
        }
        return s;
    }
};

// don't flip actually. instead have flip count. 
class Bitset {
public:
    vector<int> v;
    int cnt = 0;
    int l = 0;
    int flip_cnt = 0;
    Bitset(int size) {
        v = vector<int>(size, 0);
        cnt = 0;
        l = size;
    }

    void fix(int idx) {
        if ((v[idx] + flip_cnt) % 2 == 0) {
            cnt++;
            v[idx] = (v[idx] + 1) % 2;
        }
    }

    void unfix(int idx) {
        if ((v[idx] + flip_cnt) % 2 == 1) {
            cnt--;
            v[idx] = (v[idx] + 1) % 2;;
        }
    }

    void flip() {

        cnt = l - cnt;
        flip_cnt++;
    }

    bool all() {
        return l == cnt;
    }

    bool one() {
        return cnt >= 1;
    }

    int count() {
        return cnt;
    }

    string toString() {
        string s;
        for (int i = 0; i < l; ++i) {
            s.push_back((v[i] + flip_cnt) % 2 + '0');
        }
        return s;
    }
};



/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */

int main() {
    char c;
    Bitset sol(5);

    sol.fix(3);
    sol.fix(1);
    sol.flip();
    cout << sol.all() << endl;
    sol.unfix(0);
    sol.flip();
    cout << sol.one() << endl;
    sol.unfix(0);
    cout << sol.count() << endl;
    cout << sol.toString() << endl;

    cin >> c;
}