#include <iostream>
#include <unistd.h>
#include <thread>

#include "process2.hpp"
#include "thread1.hpp"

using namespace std;

void Process2::Loop() {

    // for(int i = 0; i < 10; ++i) {
    //     sleep(1);
    //     cout << "Process2 : " << i << " second" << endl;
    // }

    thread t21(ThreadTask1(1, 2));
    thread t22(ThreadTask1(2, 2));

    t21.join();
    t22.join();

}