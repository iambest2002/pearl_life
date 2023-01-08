#ifndef PEAR_PUBLIC_H
#define PEAR_PUBLIC_H
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <time.h>

#define BUFFER_SIZE 128
#define STR_SIZE 1024

namespace pearl {
namespace network {
namespace log {


using namespace std;
template <class T> 
class LoggerQueue {
public:
  void push(const T &data) {
    lock_guard<mutex> lock(mutex_);
    queue_.push(data);
    condition_.notify_one();
  }
  T pop() {
    unique_lock<mutex> lock(mutex_);
    while (queue_.empty()) {
      condition_.wait(lock);
    }
    T ret = queue_.front();
    queue_.pop();
    return ret;
  }

private:
  queue<T> queue_;
  mutex mutex_;
  condition_variable condition_;
};

// 时间打印类
class TimeStamp {
public:
  TimeStamp() {}
  explicit TimeStamp(int64_t times) : m_time(times) {}
  static TimeStamp now() { return TimeStamp(time(nullptr)); }
  string to_string() {
    tm *times = localtime(&m_time);
    char buffer[BUFFER_SIZE] = {};
    snprintf(buffer, BUFFER_SIZE, "%4d-%02d-%02d %02d %02d:%02d:%02d",
             times->tm_year + 1900, times->tm_mon + 1, times->tm_mday,
             times->tm_hour, times->tm_min, times->tm_sec);
  }

private:
  int64_t m_time = 0;
};

#define LOG_INFO(logmsgformat, ...)                           \
    do                                                        \
    {                                                         \
        Logger &logger = Logger::instance();        \
        char str[STR_SIZE] = {0};                             \
        snprintf(str, STR_SIZE, logmsgformat, ##__VA_ARGS__); \
        logger.LOGINFO(str);                                 \
    } while (0);


#define LOG_ERROR(logmsgFormat, ...)                                           \
  do {                                                                         \
    Logger &logger = Logger::instance();                                       \
    logger.SetLogLevel(EnLogLevel::ERROR);                                     \
    char buf[BUFFER_SIZE] = {0};                                               \
    snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__);                          \
    logger.LOGERROR(buf);                                                      \
  } while (0);

#define LOG_FATAL(logmsgFormat, ...)                                           \
  do {                                                                         \
    Logger &logger = Logger::instance();                                       \
    logger.SetLogLevel(EnLogLevel::FATAL);                                     \
    char buf[BUFFER_SIZE] = {0};                                               \
    snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__);                          \
    logger.LOGFATAL(buf);                                                      \
    exit(-1);                                                                  \
  } while (0);

/*
introdcution:  achieve a logger module.
tips: 市面上的日志基本上就是格式  +  debug等级 + 一些其他配置。
例如Python的日志系统分时间切片， 还有等级之类的。 java的日志也很有名，
C++有一个日志是抄java实现的。 日志基本上就几个东西， 一个是等级，
还有一个是输出地方等等。
*/
enum EnLogLevel {
  INFO,
  ERROR,
  FATAL,
  DEBUG,
};

class Logger {
public:
  static Logger &instance() {
    static Logger instance; // only create once.
    return instance;
  }
  void SetLogLevel(EnLogLevel level) { m_log_level = level; }
  void LOGINFO(string msg) {
    SetLogLevel(INFO);
    log(msg);
  }
  void LOGERROR(string msg) {
    SetLogLevel(ERROR);
    log(msg);
  }
  void LOGFATAL(string msg) {
    SetLogLevel(FATAL);
    log(msg);
    exit(0);
  }
  void log(string msg) {
    string begin_info;
    switch (m_log_level) {
      case INFO: {
        begin_info = "[INFO]:";
        break;
      }
      case ERROR: {
        begin_info = "[ERROR]:";
        break;
      }
      case FATAL: {
        begin_info = "[FATAL]:";
        break;
      }
    }
    begin_info += msg;
    m_log_queue.push(begin_info);
  }

private:
  int m_log_level = 0;
  LoggerQueue<string> m_log_queue; // log cache queue.
  Logger() {
    thread write_thread([&]() {
      for (;;) {
        time_t now = time(nullptr);
        tm *now_time = localtime(&now);
        char file_name[128] = {0};
        sprintf(file_name, "%d-%d-%d_log.txt", now_time->tm_year + 1900,
                now_time->tm_mon + 1, now_time->tm_mday);
        FILE *file_ptr = fopen(file_name, "a+");
        if (file_ptr == nullptr) {
          cout << "logger file :" << file_name << "open error";
        }
        string msg = "222";
        char time_buf[128] = {0};
            sprintf(time_buf, "%2d:%2d:%2d=>", now_time->tm_hour, now_time->tm_min, now_time->tm_sec);
        msg = m_log_queue.pop();
        msg.insert(0, time_buf);
        msg += "\n";
        fputs(msg.c_str(), file_ptr);
        fclose(file_ptr);
      }
    });
    write_thread.detach();
  }
};
} // namespace log
} // namespace network
} // namespace pearl

#endif