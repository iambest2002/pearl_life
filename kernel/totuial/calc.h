#pragma once

#include <vector>
using namespace std;

// double sum(double a, double b);

// double multi(double a, double b = 2.2);

// double multi(int a, double b = 2.2);

double multi(vector<int>& a, vector<int>& b);

class Calc {
 public:
  static int global_cnt;
  Calc(const vector<int>& res, int cnt);
  Calc(int* res, int cnt, bool depth);
  Calc(vector<int>&& res, int cnt);
  ~Calc();
  double sum(const double& a, const double& b);
  double sum(vector<double>& a, vector<double>& b);

  static int get_global_cnt() { return global_cnt; }
  int get_self_cnt() { return this->m_self_cnt; }
  vector<int> m_res;
  int* m_res_pointer;

 private:
  int m_self_cnt;
  int m_depth;
};