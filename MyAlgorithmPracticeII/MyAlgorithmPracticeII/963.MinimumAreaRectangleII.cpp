// See anser : 
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

class Solution {
public:
    string getKey(int a, int b) {
        return to_string(a) + "_" + to_string(b);
    }

    double minAreaFreeRect(vector<vector<int>>& points) {
        unordered_set<string> us;
        for (auto& p : points) {
            us.insert(getKey(p[0], p[1]));
        }
        double ans = 0;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = 0; j < points.size(); ++j) {
                for (int k = j + 1; k < points.size(); ++k) {
                    if (i == j || i == k) continue;
                    int x1 = points[i][0], y1 = points[i][1];
                    int x2 = points[j][0], y2 = points[j][1];
                    int x3 = points[k][0], y3 = points[k][1];
                    if ((x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1) != 0) continue;
                    int x4 = x2 + x3 - x1, y4 = y2 + y3 - y1;
                    if (us.count(getKey(x4, y4))) {
                        double w = pow(pow(x2 - x1, 2) + pow(y2 - y1, 2), 0.5);
                        double l = pow(pow(x3 - x1, 2) + pow(y3 - y1, 2), 0.5);
                        double area = w * l;
                        if (ans == 0 || area != 0 && area < ans) {
                            ans = area;
                        }
                    }
                }
            }
        }
        return ans;
    }
};


using namespace std;

use std::collections::HashMap;
impl Solution{
    pub fn min_area_free_rect(points: Vec<Vec<i32>>) -> f64 {
        let points = points.iter().map(| p | vec![p[0] as i64, p[1] as i64]).collect::<Vec<_>>();
        let dist = | x1: i64, y1 : i64, x2 : i64, y2 : i64 | ->i64 {
            (x1 - x2).pow(2) + (y1 - y2).pow(2)
        };
        let mut centers = HashMap::new();
        for i in 0..points.len() - 1 {
            let(x1, y1) = (points[i][0], points[i][1]);
            for j in 1..points.len() {
                let(x2, y2) = (points[j][0], points[j][1]);
                centers.entry((x1 + x2, y1 + y2)).or_insert(Vec::new()).push((x1, y1, x2, y2));;
            }
        }
        let mut min_area = f64::MAX;
        let mut area = i64::MAX;
        for (_, points) in centers.into_iter() {
            if points.len() < 2 {continue; }
            for i in 0..points.len() - 1 {
                let(ax, ay, _, _) = points[i];
                for j in i + 1..points.len() {
                    let(cx, cy, dx, dy) = points[j];
                    if (cy - ay) *(dy - ay) + (cx - ax) * (dx - ax) == 0 {
                        area = dist(ax, ay, cx, cy) * dist(ax, ay, dx, dy);
                        if area > 0 {
                            min_area = min_area.min(f64::sqrt(area as f64));
                        }
                    }
                }
            }
        }
        if min_area == f64::MAX {0.0}
 else { min_area }
}
}

int main() {
    char c;
    Solution sol;
    string word = "aeioqq";

    cout << sol.countOfSubstrings(word, 1);

    cin >> c;
}