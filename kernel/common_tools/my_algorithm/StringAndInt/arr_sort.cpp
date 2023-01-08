#include "arr_sort.h"
using namespace pearl::algorithm::array_and_string;

// description: sort vector by bubble algorithm.
// input : arr  sort array | sort_rule mean up or down, the default true mean up
// keypoint:NULL
bool ArrSort::bubble_sort(std::vector<int>& arr, bool sort_rule) {
  if (sort_rule) {
    for (int i = 0; i < arr.size(); i++) {
      int index = i;
      for (int j = i + 1; j < arr.size(); j++) {
        if (arr[j] < arr[i]) {
          std::swap(arr[j], arr[i]);
          index = j;
        }
      }
    }
  } else {
    for (int i = 0; i < arr.size(); i++) {
      int index = i;
      for (int j = i + 1; j < arr.size(); j++) {
        if (arr[j] > arr[i]) {
          std::swap(arr[j], arr[i]);
          index = j;
        }
      }
    }
  }

  return true;
}

// description: sort vector by choose algorithm.
// input : arr  sort array | sort_rule mean up or down, the default true mean up
// keypoint:NULL
bool ArrSort::choose_sort(std::vector<int>& arr, bool sort_rule) {
  if (sort_rule) {
    for (int i = 0; i < arr.size(); i++) {
      int tmp = arr[i];
      int index = i;
      for (int j = i + 1; j < arr.size(); j++) {
        if (tmp > arr[j]) {
          tmp = arr[j];
          index = j;
        }
      }
      std::swap(arr[index], arr[i]);
    }
  } else {
    for (int i = 0; i < arr.size(); i++) {
      int tmp = arr[i];
      int index = i;
      for (int j = i + 1; j < arr.size(); j++) {
        if (tmp < arr[j]) {
          tmp = arr[j];
          index = j;
        }
      }
      std::swap(arr[index], arr[i]);
    }
  }
  return true;
}