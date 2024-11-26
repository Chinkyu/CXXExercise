#include <iostream>
#include <unistd.h>
#include <thread>

#include "process1.hpp"
#include "thread1.hpp"

using namespace std;

void Process1::Loop() {

    // for(int i = 0; i < 5; ++i) {
    //     sleep(1);
    //     cout << "Process1 : " << i << " second" << endl;
    // }

    
    thread t11(ThreadTask1(1, 1));
    thread t12(ThreadTask1(2, 1));

    t11.join();
    t12.join();

}