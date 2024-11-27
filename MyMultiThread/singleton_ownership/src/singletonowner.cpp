#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "process1.hpp"
#include "process2.hpp"

using namespace std;

int main()
{
  std::cout << "Main process, PID: " << getpid() << std::endl;

  // Create the first child process
  pid_t pid1 = fork();

  if (pid1 == -1)
  {
    // Fork failed
    std::cerr << "Failed to create the first process!" << std::endl;
    return 1;
  }
  else if (pid1 == 0)
  {
    // First child process code
    std::cout << "First child process, PID: " << getpid() << std::endl;
    //sleep(2); // Simulate work
    Process1 p1;
    p1.Loop();
    std::cout << "First child process, PID: " << getpid() << " finished." << std::endl;
    return 0; // End the first child process
  }

  // Create the second child process
  pid_t pid2 = fork();

  if (pid2 == -1)
  {
    // Fork failed
    std::cerr << "Failed to create the second process!" << std::endl;
    return 1;
  }
  else if (pid2 == 0)
  {
    // Second child process code
    std::cout << "Second child process, PID: " << getpid() << std::endl;
    //sleep(10); // Simulate work
    Process2 p2;
    p2.Loop();


    std::cout << "Second child process, PID: " << getpid() << " finished." << std::endl;
    return 0; // End the second child process
  }

  // Parent process waits for both child processes
  int status;
  pid_t terminated_pid;

  // Wait for the first child process to finish
  terminated_pid = waitpid(pid1, &status, 0);
  if (terminated_pid > 0)
  {
    std::cout << "Parent: First child process, PID: " << pid1 << " has completed." << std::endl;
  }

  // Wait for the second child process to finish
  terminated_pid = waitpid(pid2, &status, 0);
  if (terminated_pid > 0)
  {
    std::cout << "Parent: Second child process, PID: " << pid2 << " has completed." << std::endl;
  }

  std::cout << "Parent process is exiting now." << std::endl;

  return 0;
}
