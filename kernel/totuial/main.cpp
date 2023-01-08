#include <iostream>

#include "calc.h"
using namespace std;

int main(int args, char** argc) {
  //   double a = 0.2;
  //   int aa = 0;
  //   double b = 2.2;

  //   double c = sum(a, b);
  //   double d = multi(a, b);
  //   double e = multi(a);
  //   double f = multi(aa);

  //   cout << "c : " << c << endl;
  //   cout << "d : " << d << endl;
  //   cout << "e : " << e << endl;
  //   cout << "f : " << f << endl;

  //   for (int i = 0; i < 10; ++i) {
  //     cout << "i:" << i << endl;
  //   }
  ;
  vector<int> res{1, 23, 43, 54, 5, 46, 5, 34, 3};
  Calc b(res, 0);
  cout << "b  :" << b.m_res[0] << endl;
  cout << b.m_res[0] << endl;
  int a = 111;
  int* p = new int(22);

  int* q = new int(23);
  Calc c(p, 0, 0);
  Calc d(q, 0, 1);

  cout << res[0] << endl;
  cout << "ponter:" << (*(c.m_res_pointer)) << endl;
  *p = 3;
  *q = 3;
  cout << "c ponter:" << (*(c.m_res_pointer)) << endl;
  cout << "d  ponter:" << (*(d.m_res_pointer)) << endl;
  delete p;
  delete q;

  // 右值引用
  vector<int> res_two = {3232, 43, 5, 4, 5, 34, 3};
  Calc f(std::move(res_two), 0);
  Calc g(vector<int>(3, 1), 0);
  cout << "f  :" << f.m_res[0] << endl;
}