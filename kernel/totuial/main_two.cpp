#include <iostream>

#include "calc_origin.hpp"
using namespace std;

int calc(Calc* input, int a, int b) {
  int answer = input->handle(a, b);
  cout << "cnt :" << input->get_cnt() << endl;

  return answer;
}

int main(int args, char** argc) {
  int a = 10;
  int b = 2;
  Calc* p = new Sum(3);
  Multi* q = new Multi(4);

  // Sum aa(1);
  // Multi bb(2);

  // cout << calc(&aa, a, b) << endl;
  // cout << calc(&bb, a, b) << endl;
  cout << calc(p, a, b) << endl;
  cout << calc(q, a, b) << endl;
  delete p;
  // delete q;
}