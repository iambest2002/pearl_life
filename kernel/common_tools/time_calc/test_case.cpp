
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include "common_tools/time_interval.hpp"
using namespace std;
int main() {
  vector<string> in;
  int count = 10000000;
  {
    TIME_INTERVAL_SCPOE("reserver time:");
    // in.reserve(count);
  }

  {
    TIME_INTERVAL_SCPOE("push_back time:");
    for (int i = 0; i < count; i++) {
      string temp("test");
      in.push_back(temp);
    }
  }
  in.clear();
  {
    TIME_INTERVAL_SCPOE("push_back move(string) time:");
    for (int i = 0; i < count; i++) {
      std::string temp("test");
      in.push_back(std::move(temp));
    }
  }
  in.clear();
  {
    TIME_INTERVAL_SCPOE("push_back && time:");
    for (int i = 0; i < count; i++) {
      in.push_back("test");
    }
  }
  in.clear();
  {
    TIME_INTERVAL_SCPOE("emplace back time :");
    for (int i = 0; i < count; i++) {
      in.push_back("test");
    }
  }
  map<int, string> res;
  {
    TIME_INTERVAL_SCPOE("insert time:");
    for (int i = 0; i < count; i++) {
      pair<int, string> STL = {i, "test"};
      res.insert(STL);
    }
  }
  res.clear();
  {
    TIME_INTERVAL_SCPOE("insert && time:");
    for (int i = 0; i < count; i++) {
      res.insert({i, "test"});
    }
  }
  res.clear();
  {
    TIME_INTERVAL_SCPOE("emplace && time:");
    for (int i = 0; i < count; i++) {
      pair<int, string> STL = {i, "test"};
      res.emplace(STL);
    }
  }
  res.clear();
  {
    TIME_INTERVAL_SCPOE("map [] = time:");
    for (int i = 0; i < count; i++) {
      res[i] = "test";
    }
  }
  unordered_map<int, string> res2;
  {
    TIME_INTERVAL_SCPOE("hash insert && time:");
    for (int i = 0; i < count; i++) {
      pair<int, string> STL = {i, "test"};
      res2.insert(STL);
    }
  }
  unordered_map<int, string>::iterator answer;
  {
    TIME_INTERVAL_SCPOE("hash find  time:");
    for (int i = 0; i < count / 100; i++) {
      if ((answer = res2.find(i)) != res2.end()) {
        // cout << answer->second << endl;
        ;
      }
    }
  }
  map<int, string>::iterator answer1;
  {
    TIME_INTERVAL_SCPOE("map find  time:");
    for (int i = 0; i < count / 100; i++) {
      if ((answer1 = res.find(i)) != res.end()) {
        // cout << answer1->second << endl;
        ;
      }
    }
  }
}
