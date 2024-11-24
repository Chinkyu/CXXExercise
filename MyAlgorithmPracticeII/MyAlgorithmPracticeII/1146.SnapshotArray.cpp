//  답봤음 : 수정항목만 저장하는 index 별로 pair, value 로 저장 
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
#include <functional>

using namespace std;

class SnapshotArray {
public:
    vector<vector<pair<int, int>>> v;
    int id;
    SnapshotArray(int length) {
        v = vector<vector<pair<int, int>>>(length, vector<pair<int, int>>(1, { 0,0 }));
        id = 0;

    }
    void set(int index, int val) {
        if (v[index][v[index].size() - 1].first < id)
            v[index].push_back({ id,val });
        else {
            v[index][v[index].size() - 1].second = val;
        }
    }

    int snap() {
        int turn = id;
        id++;
        return turn;
    }

    int get(int index, int snap_id) {
        int low = 0, high = v[index].size() - 1;
        if (v[index][v[index].size() - 1].first <= snap_id)return v[index][v[index].size() - 1].second;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (v[index][mid].first <= snap_id && v[index][mid + 1].first > snap_id)return v[index][mid].second;
            if (v[index][mid].first < snap_id)low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */


class _SnapshotArray {
public:
    vector<int> cv;
    vector<vector<int>> sv;
    unordered_map<int, int> cm;
    vector<unordered_map<int, int>> sm;
    int idx = 0;

    SnapshotArray(int length) {
        cv = vector<int>(length, 0);
        sv.clear();
        cm.clear();
        sm.clear();
        idx = 0;
    }

    void set(int index, int val) {
        cv[index] = val;
        cm[index] = val;
    }

    int snap() {
        if(sm.size() % 10 == 0) sv.push_back(cv);

        sm.push_back(cm);
        cm.clear();
        return sm.size() - 1;
    }

    int get(int index, int snap_id) {

        int s = snap_id / 10;
        int num = sv[s][index];
        for (int i = s * 10 + 1; i < snap_id; ++i) {
            if (sm[i].find(index) != sm[i].end()) {
                num = sm[i][index];
            }
        }

        return num;
    }
};


// memory limit exceed 
class _SnapshotArray {
public:
    vector<int> cv;
    vector<vector<int>> sv;
    SnapshotArray(int length) {

    }

    void set(int index, int val) {
        cv[index] = val;
    }

    int snap() {
        class SnapshotArray {
        public:
            vector<int> cv;
            vector<vector<int>> sv;
            SnapshotArray(int length) {
                cv = vector<int>(length, 0);
                sv.clear();
            }

            void set(int index, int val) {
                cv[index] = val;
            }

            int snap() {
                sv.push_back(cv);
                return sv.size() - 1;
            }

            int get(int index, int snap_id) {
                return sv[snap_id][index];
            }
        };
    }

    int get(int index, int snap_id) {
        return sv[snap_id][index];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 2, 10, 3, 2 };

    cout << sol.minimumRemoval(nums);

    cin >> c;
}