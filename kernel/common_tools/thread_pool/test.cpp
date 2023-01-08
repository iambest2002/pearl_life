#include <iostream>
#include <sstream>

#include "thread_pool.h"

int main() {
  auto tp = ThreadPoolImpl::GetInstance();

  for (int i = 0; i < 1000; i++) {
    std::stringstream ss;
    ss << "inc" << i;
    tp->PostTask(
        []() {
          volatile int cnt = 0;
          for (int i = 0; i < 100000; i++) {
            cnt += i;
            if (i / 3 == 0) {
              cnt++;
            }
          }
        },
        ss.str());
  }
  return 0;
}