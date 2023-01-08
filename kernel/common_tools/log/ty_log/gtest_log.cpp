#include "gtest/gtest.h"

#include "logger.h"
#include "timestamp.h"
TEST(testAdd, test0) {
  	Logger& my_log = Logger::instance();
	my_log.set_log_level(INFO);
	LOG_INFO("ok");
}
