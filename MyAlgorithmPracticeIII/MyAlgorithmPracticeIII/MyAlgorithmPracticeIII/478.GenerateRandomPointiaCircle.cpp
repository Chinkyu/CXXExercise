// ok... seems rong?? 
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
#include <numeric>

using namespace std;

class Solution {
public:
    double x, y;
    double rad;
    Solution(double radius, double x_center, double y_center) {
        x = x_center;
        y = y_center;
        rad = radius;
    }

    vector<double> randPoint() {
        // 1. Obtain a random seed from the hardware
        std::random_device rd;

        // 2. Standard mersenne_twister_engine seeded with rd()
        std::mt19937 gen(rd());

        // 3. Define the range [inclusive, inclusive]
        std::uniform_real_distribution<double> dist1(0.0, 360.0);

        std::uniform_real_distribution<double> dist2(0.0, rad);
        
        double degree = dist1(gen);
        double r = dist2(gen);

        const double PI = 3.14159265358979323846;

        double dx = r * cos(degree * (PI / 180.0));
        double dy = r * sin(degree * (PI / 180.0));

        double distance = std::hypot(dx, dy);
        if (distance > rad) {
            cout << "wrong : r = " << r << " long distance = " << distance << endl;
        }

        vector<double> ans;
        ans.push_back(x + dx);
        ans.push_back(y + dy);

        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */

int main() {
    char c;

    Solution sol(0.01, -73839.1, -3289891.3);

    for (int i = 0; i < 10; ++i) {
        vector<double> ans = sol.randPoint();
        cout << ans[0] << " " << ans[1] << endl;
    }

    cin >> c;
}
