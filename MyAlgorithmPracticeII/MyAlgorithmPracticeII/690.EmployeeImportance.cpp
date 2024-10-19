// easy : while vs do  while????
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


// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};


class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> m;

        for (int i = 0; i < employees.size(); ++i) {
            m[employees[i]->id] = employees[i];
        }

        queue<int> q;
        int ans = 0;
        q.push(id);
        ans += m[id]->importance;

        while (!q.empty()) {
            int t_id = q.front();
            q.pop();

            //if (m.find(t_id) != m.end()) 
            {

                for (auto& it : m[t_id]->subordinates) {
                    q.push(it);
                    ans += m[it]->importance;
                }
            }
        };

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<string> deadends = { "0201", "0101", "0102", "1212", "2002" };
    string target = "0202";


    cout << sol.openLock(deadends, target);

    cin >> c;
}