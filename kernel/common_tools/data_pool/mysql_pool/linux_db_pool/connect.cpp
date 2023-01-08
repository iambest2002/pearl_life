#include "connect.h"

#include <iostream>
using namespace std;

#include "public.h"

Connect::Connect() { 
  conn_ = mysql_init(nullptr); 
}
Connect::~Connect() {
  if (!conn_) {
    mysql_close(conn_);
  }
}

bool Connect::connect(string ip, unsigned short int port, string user,
                      string password, string dbname) {
  MYSQL* p =
      mysql_real_connect(conn_, ip.c_str(), user.c_str(), password.c_str(),
                         dbname.c_str(), port, nullptr, 0);
  if (p == nullptr) {
    LOG("mysql connect failed");
    return false;
  } else {
    return true;
  }
}

bool Connect::update(string sql) {
  if (mysql_query(conn_, sql.c_str())) {
    LOG("update error" + sql);
    return false;
  } else {
    return true;
  }
}

MYSQL_RES* Connect::query(string sql) {
  if (mysql_query(conn_, sql.c_str())) {
    LOG("query  error" + sql);
    return nullptr;
  }
  return mysql_use_result(conn_);
}