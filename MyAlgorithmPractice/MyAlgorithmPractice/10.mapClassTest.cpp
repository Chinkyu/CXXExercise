#include <iostream>
#include <map>

using namespace std;

class Db {

public:
	map<int, int> students;

public:
	void getAllStudent() {
		for (auto it : students) {
			cout << it.first << " " << it.second << endl;;
		}
	}

	void buildStudentList() {
		students[0] = 1;
		students[1] = 2;
	}
};

int main() {
	Db db;
	char c;

	db.buildStudentList();
	db.getAllStudent();

	cin >> c;
}