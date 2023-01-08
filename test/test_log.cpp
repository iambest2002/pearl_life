// #include "gtest/gtest.h"
// #include "pearl_public.hpp"
 
// TEST(testAdd, test0) {
// 	LOG_INFO << "2";
//   	EXPECT_EQ(15, 25);
// }


// TEST(testAdd, test1) {
// 	LOG_INFO << "2";
//   	EXPECT_EQ(15, 25);
// }


#include <iostream>
#include "pearl_public.hpp"
using namespace pearl::network::log;
int main() {
	LOG_INFO( "2%d", 2);
	LOG_ERROR( "2%d", 2);
	int i = 0;
	while(i < 100000) {
		i = i + 1;
	}
}