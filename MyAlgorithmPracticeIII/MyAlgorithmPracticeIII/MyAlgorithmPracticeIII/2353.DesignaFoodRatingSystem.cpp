// see answer : use   map<sting, set<pair<int, string>>    => this one also forted as first item. 
// instead of set value as negative,, can get last element of set 
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


class FoodRatings {
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRating;
    unordered_map<string, set<pair<int, string>>> cuisineToFoods;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
            cuisineToFoods[cuisines[i]].insert({ -ratings[i], foods[i] });
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        int oldRating = foodToRating[food];
        cuisineToFoods[cuisine].erase({ -oldRating, food });
        cuisineToFoods[cuisine].insert({ -newRating, food });
        foodToRating[food] = newRating;
    }

    string highestRated(string cuisine) {
        return cuisineToFoods[cuisine].begin()->second;
    }
};

// timeout .. 
class FoodRatings {
public:
    map<string, int> fm; // food rate map
    map<string, string> fcm; // food cosines map
    map<string, string>  cm; // cousines max food map
    map<string, vector<string>> clm; // cousine food map

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int l = foods.size();

        for (int i = 0; i < l; ++i) {
            fm[foods[i]] = ratings[i];
            fcm[foods[i]] = cuisines[i];
            clm[cuisines[i]].push_back(foods[i]);

            if (cm.find(cuisines[i]) == cm.end()) {
                cm[cuisines[i]] = foods[i];
            }
            else {
                if (ratings[i] > fm[cm[cuisines[i]]]) {
                    cm[cuisines[i]] = foods[i];
                }
                else if (ratings[i] == fm[cm[cuisines[i]]] &&
                        foods[i] < cm[cuisines[i]]) {
                    cm[cuisines[i]] = foods[i];
                }
            }
        }
    }

    void changeRating(string food, int newRating) {

        // max -> decrease
        if (food == cm[fcm[food]] && newRating < fm[cm[fcm[food]]]) {
            fm[food] = newRating;
            // recalcurate 
            int r = 0;
            string maxfood;
            for (auto& it : clm[fcm[food]]) {
                if (fm[it] > r) {
                    maxfood = it;
                    r = fm[it];
                }
                else if (fm[it] == r) {
                    maxfood = (maxfood > it) ? it : maxfood;
                }
            }
            cm[fcm[food]] = maxfood;
            return;
        }


        fm[food] = newRating;

        if (newRating > fm[cm[fcm[food]]]) {
            cm[fcm[food]] = food;
            return;
        }
        else if (newRating == fm[cm[fcm[food]]] &&
            food < cm[fcm[food]]) {
            cm[fcm[food]] = food;
            return;
        } 

    }

    string highestRated(string cuisine) {
        return cm[cuisine];
    }
};


class _FoodRatings {
public:
    map<string, int> fm; // food map
    map<string, vector<string>>  cm; // cousines map

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int l = foods.size();

        for (int i = 0; i < l; ++i) {
            fm[foods[i]] = ratings[i];
            cm[cuisines[i]].push_back(foods[i]);
        }
    }

    void changeRating(string food, int newRating) {
        fm[food] = newRating;
    }

    string highestRated(string cuisine) {

        int r = 0;
        string ans;
        for (auto& it : cm[cuisine]) {
            if (fm[it] > r) {
                ans = it;
                r = fm[it];
            }
            else if (fm[it] == r) {
                ans = (ans > it) ? it : ans;
            }
        }

        return ans;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

int main() {
    char c;
    Solution sol;
    vector<vector<int>> buildings = { {0, 1}, {2, 1}, {3, 1}, {1, 4}, {2,4} };

    vector<int> ans = sol.findSmallestSetOfVertices(5, buildings);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
