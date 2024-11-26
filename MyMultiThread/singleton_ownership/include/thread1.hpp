#ifndef THREAD1_H
#define THREAD1_H

#include <iostream>

#include "cib_mgr.hpp"

using namespace std;

class ThreadTask1 {
 public:
  ThreadTask1(int thread_num, int process_num)
      : thread_num_(thread_num), process_num_(process_num) {}

  void operator()() {
    // for (int i = 0; i < 5; ++i) {
    //   sleep(1);
    //   cout << "Process : " << process_num_ << " Thread : " << thread_num_
    //        << " sec : " << i << endl;
    // }

    while(false == cib_mgr_.acquireWriterPermit()) {
      sleep(3);
    }

    cib_mgr_.doSomething1();

    cib_mgr_.doSomething2();

    cib_mgr_.releaseWriterPermit();



  }

 private:
  int thread_num_;
  int process_num_;

  CysInfoBlockMgr& cib_mgr_ = CysInfoBlockMgr::getInstance();

};

#endif //~ THREAD1_H