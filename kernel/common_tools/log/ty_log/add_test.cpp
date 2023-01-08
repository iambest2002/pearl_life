
#include "gtest/gtest.h"

#include "add.h"
 
TEST(testAdd, test0)
{
  EXPECT_EQ(15, add(5, 10));
}