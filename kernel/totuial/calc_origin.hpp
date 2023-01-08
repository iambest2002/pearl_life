
#include <iostream>
#include <vector>

using namespace std;

// Calc::Calc(const vector<int>& res, int cnt) {
//   m_res = res;
//   m_self_cnt = cnt;
//   cout << "init & ok " << endl;
// }

class Calc {
 public:
  Calc(int res) {
    father_cnt = res;
    cout << "father" << endl;
  }
  ~Calc() { cout << "father!" << endl; }
  virtual int handle(int a, int b) { father_cnt++; }
  virtual int get_cnt() { return father_cnt; }
  int father_cnt;
};

class Sum : public Calc {
 public:
  Sum(int res) : Calc(20), sum_cnt(res) { cout << "Sum" << endl; }
  ~Sum() { cout << "Sum!" << endl; }
  int handle(int a, int b) {
    sum_cnt++;
    return a + b;
  }
  int get_cnt() { return sum_cnt; }
  int sum_cnt;
};

class Multi : public Calc {
 public:
  Multi(int res) : Calc(10), multi_cnt(res) { cout << "Multi" << endl; }
  ~Multi() { cout << "Multi!" << endl; }
  int handle(int a, int b) {
    multi_cnt++;
    return a * b;
  }
  int get_cnt() { return multi_cnt; }
  int multi_cnt;
};
