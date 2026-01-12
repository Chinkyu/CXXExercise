// use operator set and map
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

class TaskManager {
public:
    struct Task {
        int uid;
        int tid;
        int priority;

        // Custom comparator for std::set to handle tie-breaking
        bool operator<(const Task& other) const {
            if (priority != other.priority) {
                return priority > other.priority; // Higher priority first
            }
            return tid > other.tid; // Tie-break: Higher task_id first
        }
    };

    set<Task> s;
    unordered_map<int, Task> taskm;

    TaskManager(vector<vector<int>>& tasks) {
        for (auto& it : tasks) {
            Task t = { it[0], it[1], it[2] };
            s.insert(t);
            taskm[it[1]] = t;  // task id 
        }
    }

    void add(int userId, int taskId, int priority) {
        Task t = { userId, taskId, priority};
        s.insert(t);
        taskm[taskId] = t;  // task id 
    }

    void edit(int taskId, int newPriority) {
        s.erase(taskm[taskId]);
        taskm[taskId].priority = newPriority;
        s.insert(taskm[taskId]);
    }

    void rmv(int taskId) {
        s.erase(taskm[taskId]);
        taskm.erase(taskId);
    }

    int execTop() {
        if (s.size() > 0) {
            Task t = *s.begin();
            s.erase(t);
            taskm.erase(t.tid);

            return t.uid;
        }
        else {
            return -1;
        }
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */

int main() {
    char c;
    vector<vector<int>> tasks = { {1, 101, 10},{2, 102, 20},{3, 103, 15 } };

    TaskManager sol(tasks);

    sol.add(4, 104, 5);
    sol.edit(102, 8);
    cout << sol.execTop();

    cin >> c;
}
