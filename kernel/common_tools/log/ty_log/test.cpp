

#include "logger.h"
#include "timestamp.h"

int main() {
	Logger& my_log = Logger::instance();
	my_log.set_log_level(INFO);
	LOG_INFO("ok");

}