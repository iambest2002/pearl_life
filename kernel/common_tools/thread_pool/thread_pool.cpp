
/*
 * Date:2022-09-01
 * Author: Tian yi
 * funtion:  ThreadPoolImpl
 * Description :  使用ThreadPoolImpl包含多个线程，
 * 这些线程绑定了自己的成员函数WorkThreadMain， 在
 * 成员函数中检查任务队列的信号量， 然后每个线程创建一个任务去任务队列取任务，
 * 然后执行。| 外部main函数通过
 * postTask函数放任务过来给函数对象functional（被vector存储了）。
 * Example:
 * Reference:
 * command :g++ main.cpp  thread_pool.cpp   -lpthread -std=c++14 -o a
 */

#pragma once

#include "thread_pool.h"

#include <poll.h>
#include <sys/eventfd.h>
#include <sys/timerfd.h>
#include <unistd.h>

#include <chrono>
#include <iostream>
#include <memory>
#include <mutex>

ThreadPool* ThreadPool::GetInstance() { return ThreadPoolImpl::GetInstance(); }

TaskQueue::TaskQueue() { sem_init(&taskSem, false, 0); }

TaskQueue::~TaskQueue() { sem_destroy(&taskSem); }

void TaskQueue::PostTask(struct Task task) {
  {
    std::lock_guard<std::mutex> lock(tasksMutex);
    push_back(task);
  }
  sem_post(&taskSem);
}

void TaskQueue::WaitTask() { sem_wait(&taskSem); }

void TaskQueue::TakeTask(struct Task& task) {
  {
    std::lock_guard<std::mutex> lock(tasksMutex);
    task = front();
    pop_front();
  }
}
void TaskQueue::Lock() { tasksMutex.lock(); }

void TaskQueue::Unlock() { tasksMutex.unlock(); }

ThreadPoolImpl* ThreadPoolImpl::GetInstance() {
  if (instance == nullptr) {
    static std::mutex mutex;
    std::lock_guard<std::mutex> lock(mutex);
    if (instance == nullptr) {
      instance = new ThreadPoolImpl();
    }
  }
  return instance;
}

void ThreadPoolImpl::PostTask(ThreadPoolTask task, std::string name) {
  runnable.PostTask({task, name});
}

ThreadPoolImpl::ThreadPoolImpl() {
  // 绑定过来
  int cpuNumber = 2;
  for (int i = 0; i < cpuNumber; i++) {
    auto func = std::bind(&ThreadPoolImpl::WorkThreadMain, this, i);
    workThreads.push_back(std::make_unique<std::thread>(func));
  }
}

ThreadPoolImpl::~ThreadPoolImpl() {
  running = false;
  for (auto& workThread : workThreads) {
    workThread->join();
  }
}

void ThreadPoolImpl::WorkThreadMain(int id) {
  while (true) {
    runnable.WaitTask();
    if (running == false) {
      break;
    }
    Task task;
    runnable.TakeTask(task);

    std::cout << "Work(" << id << "): " << task.name << " started" << std::endl;
    task.task();
    std::cout << "Work(" << id << "): " << task.name << " end" << std::endl;
  }
}
