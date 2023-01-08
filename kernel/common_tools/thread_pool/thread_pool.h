

#pragma once

#include <semaphore.h>

#include <atomic>
#include <functional>
#include <iostream>
#include <list>
#include <memory>
#include <mutex>

#include <string>
#include <thread>
#include <vector>

using ThreadPoolTask = std::function<void()>;

class ThreadPool {
 public:
  static ThreadPool* GetInstance();
  virtual void PostTask(ThreadPoolTask task, std::string name = "") = 0;
};

struct Task {
  ThreadPoolTask task;
  std::string name;
};

class TaskQueue : public std::list<Task> {
 public:
  TaskQueue();
  ~TaskQueue();
  void PostTask(struct Task task);
  void WaitTask();
  void TakeTask(struct Task& task);
  void Lock();
  void Unlock();

 private:
  std::mutex tasksMutex;  // 这个怎么初始化？ 这不可能是声明，
                          // 哪有声明类但是不初始化的。
  sem_t taskSem;
};
class ThreadPoolImpl : public ThreadPool {
 public:
  static ThreadPoolImpl* GetInstance();
  virtual void PostTask(ThreadPoolTask task, std::string name) override;

 private:
  ThreadPoolImpl();
  ~ThreadPoolImpl();
  static inline ThreadPoolImpl* instance = nullptr;
  int interruptFd = -1;
  void WorkThreadMain(int id);
  TaskQueue runnable;
  std::vector<std::unique_ptr<std::thread>> workThreads;  // thread work
  std::unique_ptr<std::thread> futureThread = nullptr;    // fucntion of thread,
                                                          // stop args
  std::atomic_bool running = {true};
};