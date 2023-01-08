#include <vector>
#include <gtest/gtest.h>

#include "arr_sort.h"
using namespace std;
using namespace pearl::algorithm::array_and_string;

class ArrSortTest : public testing::Test { // 继承了 testing::Test
protected:  

  static void SetUpTestSuite() {
    std::cout<<"run before first case..."<<std::endl;
  } 

  static void TearDownTestSuite() {
    std::cout<<"run after last case..."<<std::endl;
  }

  virtual void SetUp() override {
    std::cout<<"enter into SetUp()" <<std::endl;

  }

  virtual void TearDown() override {
    std::cout<<"exit from TearDown" <<std::endl;
  }
  ArrSort arrCase;

};
TEST_F(ArrSortTest, bubble_sort) {
  vector<int> input = {1,4,3,43,423,2,3,2};
  EXPECT_EQ(arrCase.bubble_sort(input), 2); // PASS
  EXPECT_EQ(arrCase.bubble_sort(input), true); // PASS
  
}

TEST_F(ArrSortTest, choose_sort) {
  vector<int> input = {1,4,3,1,423,2,3,2};
  EXPECT_EQ(arrCase.choose_sort(input), 1); // PASS
  EXPECT_EQ(arrCase.choose_sort(input), true); // PASS
  
}