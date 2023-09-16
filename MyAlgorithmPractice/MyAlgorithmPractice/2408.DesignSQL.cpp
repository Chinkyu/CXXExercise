//  just debugging  matter 
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

class SQL {
public:
	unordered_map<string, int> nm;
	//unordered_map<string, int> nm_cnt;
	vector<vector<vector<string>>> m;

	SQL(vector<string>& names, vector<int>& columns) {
		int l = names.size();
		m = vector<vector<vector<string>>>(l);

		for (int i = 0; i < l; ++i) {
			nm[names[i]] = i;
			//nm_cnt[names[i]]
		}

	}

	void insertRow(string name, vector<string> row) {
		int idx = nm[name];
		m[idx].push_back(row);
	}

	void deleteRow(string name, int rowId) {
		int idx = nm[name];
		m[idx][rowId-1][0] = "deleted";
	}

	string selectCell(string name, int rowId, int columnId) {
		int idx = nm[name];
		return m[idx][rowId-1][columnId-1];
	}
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * obj->insertRow(name,row);
 * obj->deleteRow(name,rowId);
 * string param_3 = obj->selectCell(name,rowId,columnId);
 */

int main() {
	char c;

	vector<string> name = { "one", "two", "three" };
	vector<int> columns = { 2, 3, 1 };

	SQL sql(name, columns);

	sql.insertRow("two", {"first", "second", "third"});
	cout << sql.selectCell("two", 1, 3) << endl;
	sql.insertRow("two", { "forth", "firth", "sixth" });
	sql.deleteRow("two", 1);
	cout << sql.selectCell("two", 2, 2) << endl;

	cin >> c;
}