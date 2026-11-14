// Ok. : 꽁수.. 
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

class _Solution {
public:
    int getWinner(vector<int>& arr, int k) {

        int win_cnt = 0, win_num = -1;

        if (arr.size() <= k) {
            // find max
            for (auto& it : arr) {
                win_num = max(win_num, it);
            }
            return win_num;
        }

        do {
            if (arr[0] > arr[1]) {
                if (arr[0] == win_num) {
                    win_cnt++;
                }
                else {
                    win_num = arr[0];
                    win_cnt = 1;
                }

                int t = arr[1];
                arr.erase(arr.begin() + 1);
                arr.push_back(t);
            }
            else { // arr[0] < arr[1]
                if (arr[1] == win_num) {
                    win_cnt++;
                }
                else {
                    win_num = arr[1];
                    win_cnt = 1;
                }

                int t = arr[0];
                arr.erase(arr.begin() + 0);
                arr.push_back(t);
            }


        } while (win_cnt < k);


        return win_num;
    }
};

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {

        int win_cnt = 0, win_num = -1;

        if (arr.size() < k + 2) {  //  마지막 케이스 때문에  + 2... 
            // find max
            for (auto& it : arr) {
                win_num = max(win_num, it);
            }
            return win_num;
        }

#if 0
        if (k == 99999) {
            // find max
            for (int i = 0; i < k; i++) {
                win_num = max(win_num, arr[i]);
            }

            if (arr[0] == win_num) {
                return win_num;
            }
        }
#endif 

        do {
            if (arr[0] > arr[1]) {
                if (arr[0] == win_num) {
                    win_cnt++;
                }
                else {
                    win_num = arr[0];
                    win_cnt = 1;
                }

                int t = arr[1];
                arr.erase(arr.begin() + 1);
                arr.push_back(t);
            }
            else { // arr[0] < arr[1]
                if (arr[1] == win_num) {
                    win_cnt++;
                }
                else {
                    win_num = arr[1];
                    win_cnt = 1;
                }

                int t = arr[0];
                arr.erase(arr.begin() + 0);
                arr.push_back(t);
            }


        } while (win_cnt < k);


        return win_num;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> arr = { 2,1,3,5,4,6,7 };

    cout << sol.getWinner(arr, 2);
    cin >> c;
}