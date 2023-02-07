#include <iostream>
#include <thread>

using namespace std;

void thread_function() {

	for (int i = 0; i <= 2000; ++i) {
		cout << "1";
		cout << "2";
		cout << "3";
		cout << endl;
	}
}

int main() {

	thread t(&thread_function);

	for (int i = 0; i <= 2000; ++i) {
		cout << "a";
		cout << "b";
		cout << "c";
		cout << endl;
	}

	t.join();   // main thread waits for the thread t to finish
	return 0;
}