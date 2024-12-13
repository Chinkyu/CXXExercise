//   ¥‰∫√¿Ω : two pointer.. 
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


class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());


        int i = 0;
        int j = people.size() - 1;
        int count = 0;
        while (i <= j)
        {
            if (people[i] + people[j] <= limit)
            {
                i++;
            }
            j--;
            count++;
        }

        return count;
    }
};

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end(), greater<int>());

        int l = people.size();
        int ans = 0;
        int acc = 0;
        for (int i = 0; i < l; ++i) {
            if (acc + people[i] > limit) {
                ans++;
                acc = people[i];
                continue;
            }

            if (acc + people[i] + people[l - 1] <= limit) {
                acc += people[i] + people[l - 1];
                l--;
                continue;
            }

            acc += people[i];
        }

        if (acc > 0) ans++;
        return ans;
    }
};



class _Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int ans = 0;
        int acc = 0;
        for (int i = 0; i < people.size(); ++i) {
            if (acc + people[i] > limit) {
                ans++;
                acc = people[i];
                continue;
            }
            acc += people[i];
        }

        if (acc > 0) ans++;
        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<int> people = {5, 1, 4, 2};

    cout << sol.numRescueBoats(people, 6);

    cin >> c;
}