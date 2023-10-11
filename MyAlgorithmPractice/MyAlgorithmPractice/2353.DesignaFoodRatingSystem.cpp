// set  이  assending order로  소팅 되는것을 이용해서... 쉽게 품.. 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

// Using Set... 
class FoodRatings {
public:
	unordered_map<string, set<pair<int, string>>> cuisine_ratings;
	unordered_map<string, string> food_cuisine;
	unordered_map<string, int> food_rating;
	FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
		for (int i = 0; i < foods.size(); ++i) {
			cuisine_ratings[cuisines[i]].insert({ -ratings[i], foods[i] });
			food_cuisine[foods[i]] = cuisines[i];
			food_rating[foods[i]] = ratings[i];
		}
	}
	void changeRating(string food, int newRating) {
		auto &cuisine = food_cuisine.find(food)->second;
		cuisine_ratings[cuisine].erase({ -food_rating[food], food });
		cuisine_ratings[cuisine].insert({ -newRating, food });
		food_rating[food] = newRating;
	}
	string highestRated(string cuisine) {
		return begin(cuisine_ratings[cuisine])->second;
	}
};


class FoodRatings_V1 {
public:
	unordered_map<string, int>  m;  // foods, ratings
	unordered_map<string, vector<string>> cm;  // cuisines map - cousine, food
	FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
		m.clear();
		cm.clear();
		
		int l = foods.size();

		for (int i = 0; i < l; ++i) {
			m[foods[i]] = ratings[i];
			cm[cuisines[i]].push_back(foods[i]);
		}
		
	}

	void changeRating(string food, int newRating) {
		m[food] = newRating;
	}

	string highestRated(string cuisine) {

		vector<string> v = cm[cuisine];

		sort(v.begin(), v.end(), [&](string &l, string &r) {
			if (m[l] == m[r]) {
				return l < r;
			}
			else {
				return m[l] > m[r];
			}
		});

		return v[0];
	}
};

class FoodRatings {
public:
	unordered_map<string, int>  m;  // foods, ratings
	unordered_map<string, string> cm;  // cuisine map : food, cousine
	unordered_map<string, vector<string>> cvm;  // cuisines map - cousine, food
	unordered_map<string, string> maxc;  // cuisine = max, food
	FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
		m.clear();
		cvm.clear();

		int l = foods.size();

		for (int i = 0; i < l; ++i) {
			m[foods[i]] = ratings[i];
			cm[foods[i]] = cuisines[i];
			cvm[cuisines[i]].push_back(foods[i]);


			// Make maxc ; 
			if (m[maxc[cuisines[i]]] == ratings[i]) {
				if (maxc[cuisines[i]] > foods[i]) {
					maxc[cuisines[i]] = foods[i];
				}
			}
			else if (m[maxc[cuisines[i]]] < ratings[i]) {
				maxc[cuisines[i]] = foods[i];
			}
		}

	}

	void changeRating(string food, int newRating) {
		m[food] = newRating;

		string cuisine = cm[food];
		if (maxc[cuisine] == food || m[maxc[cuisine]] <= newRating) {  // sort again 
			vector<string> v = cvm[cuisine];

			sort(v.begin(), v.end(), [&](string &l, string &r) {
				if (m[l] == m[r]) {
					return l < r;
				}
				else {
					return m[l] > m[r];
				}
			});
			maxc[cuisine] = v[0];
		}

	}

	string highestRated(string cuisine) {
		return maxc[cuisine];
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

	FoodRatings sol;

	vector<int> edges = { 4,4,8,-1,9,8,4,4,1,1 };
	cout << sol.closestMeetingNode(edges, 5, 6);

	cin >> c;

}