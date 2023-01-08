/*
 * Date:2022-09-01
 * Author: Tian yi
 * funtion:  TimeInterval
 * Description : using a define to calc time consume when {} is out.
 * Example:   {TIME_INTERVAL_SCOPE("push_back string:");  sleep(2)}
 * Reference: https://blog.csdn.net/u012526003/article/details/80862801, it
 * explire why we used gettimeofday to calc time.
 */
#ifndef TIME_INTERVAL_H
#define TIME_INTERVAL_H

#include <sys/time.h>

#include <iostream>
#include <memory>
#include <string>

class TimeInterval {
 public:
  TimeInterval(const std::string& d) : detail(d) { init(); }
  TimeInterval() { init(); }
  ~TimeInterval() {
    gettimeofday(&end, NULL);
    std::cout << detail
              << 1000 * (end.tv_sec - start.tv_sec) +
                     (end.tv_usec - start.tv_usec) / 1000
              << " ms" << std::endl;
  }

 protected:
  timeval start, end;
  void init() { gettimeofday(&start, NULL); }
  std::string detail;
};

// we can used TIME_INTERVAL_SCPOE to create a TimeInterval pointer and release
// it by {}.
#define TIME_INTERVAL_SCPOE(d)                              \
  std::shared_ptr<TimeInterval> time_interval_scope_begin = \
      std::make_shared<TimeInterval>(d)
#endif