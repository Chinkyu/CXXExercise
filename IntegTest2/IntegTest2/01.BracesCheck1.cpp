#include <iostream>
#include <string>

using namespace std;

#if 0
class Stack {
public:
	void push(char c);
	int pop(char &c);   // return count : -1 == when count  
	int getCount();
};

int braces_check1(char *str) {
	Stack st;
	char c;

	for (int i; i < strlen(str); i++) {
		if (str[i] == '(') st.push(str[i]);
		if (str[i] == ')') {
			if (st.pop(c) < 0) return -1;
		}
	}

	if (st.getCount() == 0) {
		return 0;
	}
	else {
		return -1;
	}
}
#endif

bool braces_check2(string s1) {
	int b_count = 0;

	string::iterator it;
	for (string::iterator it = s1.begin(); it < s1.end(); it++) {
//		cout << *it;
//		if (*it == 't') cout << "[match]";
		if (*it == '(') b_count++;
		if (*it == ')') b_count--;
	}
//	cout << endl;
	if (b_count == 0) return true;
	else false;
}


int main() {
	char * str = "xxxx(..)..)";
	string s1("tes()t(( str)))ing");

//	for (
	cout << "results" << braces_check2(s1);


}
