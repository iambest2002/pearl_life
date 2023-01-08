
#include "calc.h"

#include <iostream>
#include <vector>

using namespace std;

// Calc::Calc(const vector<int>& res, int cnt) {
//   m_res = res;
//   m_self_cnt = cnt;
//   cout << "init & ok " << endl;
// }

int Calc::global_cnt = 0;
Calc::Calc(vector<int>&& res, int cnt) {
  cout << "into &&" << endl;
  m_res = res;
  m_self_cnt = cnt;
}
Calc::~Calc() {
  if (m_depth) {
    m_res_pointer = nullptr;

  } else {
    ;
  }
}
Calc::Calc(const vector<int>& res, int cnt) : m_self_cnt(cnt) {
  m_res = res;

  global_cnt = global_cnt + 1;
  cout << "init & ok " << endl;
}

Calc::Calc(int* res, int cnt, bool depth) : m_self_cnt(cnt) {
  m_depth = depth;
  if (m_depth) {
    m_res_pointer = new int(*res);
  } else {
    m_res_pointer = res;
  }
  global_cnt = global_cnt + 1;
  cout << "init * ok " << endl;
}

double Calc::sum(const double& a, const double& b) {
  global_cnt = global_cnt + 1;
  m_self_cnt++;
  return a + b;
  cout << "sum  double ok " << endl;
}

double Calc::sum(vector<double>& a, vector<double>& b) {
  global_cnt = global_cnt + 1;
  m_self_cnt++;
  double answer = 0.0;
  for (auto& ch : a) {
    answer = answer + ch;
  }
  for (auto& ch : b) {
    answer = answer + ch;
  }
  return answer;

  cout << "sum vector ok " << endl;
}