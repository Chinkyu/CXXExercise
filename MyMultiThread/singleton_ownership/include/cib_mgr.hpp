#ifndef CYS_INFO_BLOCK_MGR_H
#define CYS_INFO_BLOCK_MGR_H

#include <fcntl.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <thread>

#include <string_view>

using namespace std;

class CysInfoBlockMgr {
public:
  struct ShareMem {
    pid_t writer_pid;
    thread::id writer_tid;
  };

  static CysInfoBlockMgr &getInstance() {
    static CysInfoBlockMgr instance;
    return instance;
  }

  void doSomething1() {
    // Critical section: Check if the current thread has ownership
    if (share_mem_->writer_pid == getpid() &&
        share_mem_->writer_tid == std::this_thread::get_id()) {
      std::cout << "doSomething1 executed by process " << getpid()
                << ", thread " << std::this_thread::get_id() << std::endl;
      sleep(5);
    } else {
      cout << "Can not run doSomething1() << endl";
    }
  }

  void doSomething2() {
    // Critical section: Check if the current thread has ownership
    if (share_mem_->writer_pid == getpid() &&
        share_mem_->writer_tid == std::this_thread::get_id()) {
      std::cout << "doSomething2 executed by process " << getpid()
                << ", thread " << std::this_thread::get_id() << std::endl;
      sleep(2);
    } else {
      cout << "Can not run doSomething2()" << endl;
    }
  }

  bool acquireWriterPermit() {
    // Wait for the semaphore to acquire ownership
    if (sem_wait(writer_sem_) == -1) {
      perror("sem_wait failed");
      // throw std::runtime_error("Failed to acquire semaphore");
    }

    // Critical section: Check ownership
    if (share_mem_->writer_pid != -1) {
      sem_post(writer_sem_); // Release semaphore if ownership is already taken
      // throw std::runtime_error("Ownership already held by another thread.");
      cout << "[acquireWriterPermit]Ownership already held by another thread."
           << endl;
      return false;
    }

    // Acquire ownership by setting the process and thread IDs
    share_mem_->writer_pid = getpid();
    share_mem_->writer_tid = std::this_thread::get_id();

    cout << "[acquireWriterPermit] Acquire pid : " << share_mem_->writer_pid
         << " tid : " << share_mem_->writer_tid << endl;

    sem_post(writer_sem_); // Release semaphore after setting ownership

    return true;
  }

  bool releaseWriterPermit() {
    // Wait for the semaphore to release ownership
    if (sem_wait(writer_sem_) == -1) {
      perror("sem_wait failed");
      // throw std::runtime_error("Failed to acquire semaphore");
    }

    // Critical section: Release ownership if current thread is the owner
    if (share_mem_->writer_pid != getpid() ||
        share_mem_->writer_tid != std::this_thread::get_id()) {
      sem_post(writer_sem_); // Release semaphore if no ownership
      // throw std::runtime_error("Current thread does not own the singleton.");
      cout << "[releaseWriterPermit]Current thread does not own the singleton."
           << endl;
    }

    // Release ownership by resetting process and thread IDs
    share_mem_->writer_pid = -1;
    share_mem_->writer_tid = std::thread::id();

    cout << "[Writer] Release pid : " << share_mem_->writer_pid
         << " tid : " << share_mem_->writer_tid << endl;

    sem_post(writer_sem_); // Release semaphore after resetting ownership

    return true;
  }

private:
  CysInfoBlockMgr() {
    // init semaphore
    writer_sem_ = sem_open(writer_sem_name_.data(), O_CREAT, 0644, 1);
    if (SEM_FAILED == writer_sem_) {
      perror("writer_sem open failed");
    }

    // shared memory
    int shm_fd =
        shm_open(writer_shm_name_.data(), O_CREAT | O_EXCL | O_RDWR, 0644);
    bool isFirstCreator = (shm_fd != -1);

    if (!isFirstCreator) {
      shm_fd = shm_open(writer_shm_name_.data(), O_RDWR, 0644);
      if (shm_fd == -1) {
        perror("shm_open failed");
      }
    }

    if (-1 == shm_fd) {
      perror("shm_open failed");
    }

    if (ftruncate(shm_fd, sizeof(ShareMem)) == -1) {
      perror("ftruncate failed");
    }

    // map shared memory
    share_mem_ = static_cast<ShareMem *>(mmap(nullptr, sizeof(ShareMem),
                                              PROT_READ | PROT_WRITE,
                                              MAP_SHARED, shm_fd, 0));
    // share_mem_->writer_tid = static_cast<thread::id *>(
    //     mmap(nullptr, sizeof(thread::id), PROT_READ | PROT_WRITE, MAP_SHARED,
    //          shm_fd, sizeof(pid_t)));
    if (MAP_FAILED == share_mem_) {
      perror("share_mem_- mmap failed");
    }

    // if (MAP_FAILED == share_mem_->writer_tid ) {
    //   perror("share_mem_->writer_tid mmap failed");
    // }

    // init share variable
    if (isFirstCreator) {
      share_mem_->writer_pid = -1;
      share_mem_->writer_tid = thread::id();
    }
  }

  ~CysInfoBlockMgr() {
    // clean up semaphore
    sem_close(writer_sem_);
    sem_unlink(writer_sem_name_.data());

    // clean up shared memory
    munmap(share_mem_, sizeof(ShareMem));
    // munmap(share_mem_->writer_tid, sizeof(thread::id));
    shm_unlink(writer_shm_name_.data());
  }

private:
  static constexpr std::string_view writer_sem_name_{"/writer_sem"};
  static constexpr std::string_view writer_shm_name_{"/cib_shared_mem"};
  sem_t *writer_sem_{nullptr};
  ShareMem *share_mem_{nullptr};
  // pid_t *share_mem_->writer_pid;
  // thread::id *share_mem_->writer_tid;
};

#endif //~ CYS_INFO_BLOCK_MGR_H
