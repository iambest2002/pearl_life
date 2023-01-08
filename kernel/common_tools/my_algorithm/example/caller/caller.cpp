#include <iostream>

#include "my_algorithm.hpp"
using namespace std;

int main(int argc, char **argv) {
  vector<int> arr(3, 2);
  my_algorithm ans;
  ans.fast_sort(arr);
  return 0;
}