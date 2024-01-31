// hahaha : 무식하게 100번 돌리면 pass함. 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
		unordered_map<string, bool> sup;
		int l = recipes.size();
		vector<bool> make(l, false);

		for (auto &it : supplies) sup[it] = true;

		vector<string> ans;
		vector<string> not_make;
	for(int iter = 0; iter < 100; ++iter) {
		for (int i = 0; i < ingredients.size(); ++i) {

			if (make[i] == true) continue;

			bool isAllExist = true;
			for (auto &jt : ingredients[i]) {
				if (sup.find(jt) == sup.end()) {
					isAllExist = false;
					not_make.push_back(recipes[i]);
					break;
				}
			}

			if (isAllExist == true) {
				ans.push_back(recipes[i]);
				sup[recipes[i]] = true;
				make[i] = true;
			}
		}
	}


		return ans;
	}
};


int main() {
	char c;

	Solution sol;
	vector<string> recipes = { "bread", "sandwich"};
	vector<vector<string>> ingredients = {{"yeast", "flour"},{"bread", "meat"}};
	vector<string> supplies = {"yeast", "flour", "meat"};

	vector<string> ans = sol.findAllRecipes(recipes, ingredients, supplies);

	for (auto &it : ans) {
		cout << it << " ";
	}

	cin >> c;
}