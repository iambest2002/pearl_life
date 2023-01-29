#ifndef PEAR_PUBLIC_H
#define PEAR_PUBLIC_H
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <time.h>
using namespace std;

// namespace pearl {
// namespace network {
// namespace log {
// #define BUFFER_SIZE 128

// template <class Y> class LoggerQueue {
// public:
//   void push(const T &data) {
//     lock_guard<mutex> lock(mutex_);
//     queue_.push(data);
//     condition_.notify_one();
//   }
//   T pop() {
//     lock_guard<mutex> lock(mutex_);
//     while (queue_empty()) {
//       condition_.wait(lock);
//     }
//     T ret - queue_.front();
//     queue_.pop();
//     return ret;
//   }

// private:
//   queue<T> queue_;
//   mutex mutex_;
//   condition_variable cocondition_;
// };

// // 时间打印类
// class TimeStamp {
// public:
//   TimeStamp() {}
//   explicit TimeStamp(int64_t times) : m_time(times) {}
//   static TimeStamp now() { return TimeStamp(time(nullptr)); }
//   string to_string() {
//     tm *times = localtime(&m_time);
//     char buffer[BUFFER_SIZE] = {};
//     snprintf(buffer, BUFFER_SIZE, "%4d-%02d-%02d %02d %02d:%02d:%02d",
//              times->tm_year + 1900, times->tm_mon + 1, times->tm_mday,
//              times->tm_hour, times->tm_min, times->tm_sec);
//   }

// private:
//   int64_t m_time = 0;
// };

// #define LOG_INFO(logmsgFormat, ...)                                            \
//   do {                                                                         \
//     Logger &logger = logger::instance();                                       \
//     logger.SetLogLevel(EnLogLevel::INFO);                                      \
//     char buf{BUFFER_SIZE} = {};                                                \
//     snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__);                          \
//     logger.LOGINFO(buf);                                                       \
//   } while (0)

// #define LOG_ERROR(logmsgFormat, ...)                                           \
//   do {                                                                         \
//     Logger &logger = Logger::instance();                                       \
//     logger.SetLogLevel(EnLogLevel::ERROR);                                     \
//     char buf[BUFFER_SIZE] = {0};                                               \
//     snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__);                          \
//     logger.LOGERROR(buf);                                                      \
//   } while (0)

// #define LOG_FATAL(logmsgFormat, ...)                                           \
//   do {                                                                         \
//     Logger &logger = Logger::instance();                                       \
//     logger.SetLogLevel(EnLogLevel::FATAL);                                     \
//     char buf[BUFFER_SIZE] = {0};                                               \
//     snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__);                          \
//     logger.LOGFATAL(buf);                                                      \
//     exit(-1);                                                                  \
//   } while (0)

// /*
// description:  achieve a logger module.
// tips: 市面上的日志基本上就是格式  +  debug等级 + 一些其他配置。
// 例如Python的日志系统分时间切片， 还有等级之类的。 java的日志也很有名，
// C++有一个日志是抄java实现的。 日志基本上就几个东西， 一个是等级，
// 还有一个是输出地方等等。
// */
// enum EnLogLevel {
//   INFO,
//   ERROR,
//   FATAL,
//   DEBUG,
// };

// class Logger {
// public:
//   static Logger &instance() {
//     static Logger instance; // only create once.
//     return instance;
//   }
//   void SetLogLevel(EnLogLevel level) { m_log_level = level; }
//   void LOGINFO(const string &msg) {
//     SetLogLevel(INFO);
//     log(msg);
//   }
//   void LOGERROR(string msg) {
//     SetLogLevel(ERROR);
//     log(msg);
//   }
//   void LOGFATAL(string msg) {
//     SetLogLevel(FATAL);
//     log(msg);
//     exit(0);
//   }
//   void log(const string &msg) {
//     string begin_info;
//     switch (m_log_level) {
//     case INFO: {
//       begin_info = "[INFO]:";
//       break;
//     }
//     case ERROR: {
//       begin_info = "[ERROR]:";
//       break;
//     }
//     case FATAL: {
//       begin_info = "[FATAL]:";
//       break;
//     }
//       begin_info += msg;
//       m_log_queue.push(begin_info);
//     }
//   }

// private:
//   int m_log_level = 0;
//   LoggerQueue<string> m_log_queue; // log cache queue.
//   Logger() {
//     thread write_thread([&]() {
//       for (;;) {
//         time_t now = time(nullptr);
//         tm *now_time = localtime(&now);
//         char file_name[128] = {0};
//         sprintf(file_name, "%d-%d-%d_log.txt", now_time->tm_year + 1900,
//                 now_time->tm_mon + 1, now_time->tm_mday);
//         FILE *file_ptr = fopen(file_name, "a+");
//         if (file_ptr == nullptr) {
//           LOG_ERROR << "logger file :" << file_name << "open error";
//         }
//         string msg;
//         string time_prefix = TimeStamp::now().to_string();
//         msg = m_log_queue.pop();
//         msg.insert(0, time_prefix.c_str());
//         msg += "\n";
//         fputs(msg.c_str(), file_ptr);
//         fclose(file_ptr);
//       }
//     });
//     write_thread.detach();
//   }
//   Logger(const Logger &) = delete;
//   Logger(Logger &&) = delete;
//   Logger &operator=(const Logger &) = delete;
// };
// } // namespace log
// } // namespace network
// } // namespace pearl

namespace pearl {
namespace code_design {
namespace design_model {
/*
description:  a chieve singleton.
tips: 
ref: https://www.cnblogs.com/xiaolincoding/p/11437231.html
*/
class Singleton {

private:
    Singleton() {}
    ~Singleton() {}
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
public:
    static Singleton &GetInStance() {
        static Singleton ref;
        return ref;
    }
};
} // namespace design_model
} // namespace code_design
} // namespace pearl

#endif