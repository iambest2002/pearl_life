#include <iostream>
#include <string>
#include <vector>

namespace pearl {
namespace algorithm {
namespace array_and_string {

class ArrSort {
 public:
  bool fast_sort(std::vector<int>& arr, bool sort_rule);
  bool choose_sort(std::vector<int>& arr, bool sort_rule = true);
  bool bubble_sort(std::vector<int>& arr, bool sort_rule = true);
};

}  // namespace array_and_string

}  // namespace algorithm

}  // namespace pearl
