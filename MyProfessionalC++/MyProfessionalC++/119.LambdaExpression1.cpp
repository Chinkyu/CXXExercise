#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;


// Lambda Expression as Parameters

void testCallback(const vector<int>& vec, const function<bool(int)>& callback) {
	for (const auto& i : vec) {
		if (!callback(i)) {
			break;
		}
		cout << i << " ";
	}
	cout << endl;
}

void lamdaExpressionAsParameterTest() {
	vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 0, 10 };
	vector<int> vec2 = { 3, 4, 5, 6, 7, 8, 9, 10 };

	testCallback(vec, [](int i) {return i < 6; });
}

void lamdaExpressionAsParameterTest2() {
	vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 0, 10 };
	vector<int> vec2 = { 3, 4, 5, 6, 7, 8, 9, 10 };

	function<bool(int)> f1 = [](int i) {return i < 6; };

	testCallback(vec, f1);
}

//----------------------------------------------
// lamda with count_if
void lamdaWithCount_if() {
	vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int value = 3;
	int cntLambdaCalled = 0;
	int cnt = count_if(cbegin(vec), cend(vec),
		[value, &cntLambdaCalled](int i) { ++cntLambdaCalled; return i > value; });

	cout << "The lambda expression was called " << cntLambdaCalled
		<< " times." << endl;
	cout << "Found " << cnt << " values > " << value << endl;

}

//-----------------------------------------------
// lamda with generate
void lamdaWithGenerate() {
	vector<int> vec(10);
	int value = 1;
	generate(begin(vec), end(vec), [&value] {value *= 2; return value; });
	for (const auto& i : vec) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	char c;
	lamdaExpressionAsParameterTest();
	lamdaExpressionAsParameterTest2();

	lamdaWithCount_if();
	lamdaWithGenerate();
	cin >> c;
}