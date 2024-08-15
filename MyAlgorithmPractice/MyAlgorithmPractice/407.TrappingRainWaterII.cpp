// ¥‰∫√¿Ω : vector and unordered_map
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

#define pii pair<int, int>
#define piii pair<int, pii>
#define f first
#define s second

class Solution {
public:
    int m, n;
    bool isValid(int x, int y) {
        return min(x, y) >= 0 && x < m && y < n;
    }

    int trapRainWater(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        vector<vector<bool>> visited(m + 1, vector<bool>(n + 1, false));
        priority_queue<piii, vector<piii>, greater<piii>> pq;
        int dx[4] = { 1, -1, 0, 0 };
        int dy[4] = { 0, 0, 1, -1 };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({ matrix[i][j], {i, j} });
                }
            }
        }

        int ans = 0;
        while (!pq.empty()) {
            int i = pq.top().s.f;
            int j = pq.top().s.s;
            int h = pq.top().f;
            pq.pop();

            if (visited[i][j]) continue;
            visited[i][j] = 1;
            ans += h - matrix[i][j];

            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (isValid(nx, ny) && !visited[nx][ny]) {
                    pq.push({ max(h, matrix[nx][ny]), {nx, ny} });
                }
            }
        }

        return ans;
    }
};

int main() {
    Codec sol;
    char c;

    TreeNode* r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->right = new TreeNode(3);
    r->right->left = new TreeNode(4);
    r->right->right = new TreeNode(5);


    string ans = sol.serialize(r);
    cout << ans;

    TreeNode* root = sol.deserialize(ans);

    cin >> c;
}
