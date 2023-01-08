#include <mysql/mysql.h>
#include <stdio.h>
#include "connect.h"

int main() {
  char SelectAllExec[] = "select * from a";
  int ResultNum = 0;
  MYSQL_RES *Result;
  MYSQL_ROW Row;
  MYSQL ConnectPointer;
  mysql_init(&ConnectPointer);
  mysql_real_connect(&ConnectPointer, "127.0.0.1", "root", "root", "c_test", 0,
                     NULL, 0);
  if (&ConnectPointer) {
    printf("connect database successfully\n");
  } else {
    printf("failed to connect database\n");
    return -1;
  }
  // get exec result
  ResultNum = mysql_query(&ConnectPointer, SelectAllExec);
  if (ResultNum != 0) {
    printf("search data failed\n");
    return -1;
  }
  Result = mysql_store_result(&ConnectPointer);
  if (Result == NULL) {
    printf("get search data failed\n");
    return -1;
  }
  while ((Row = mysql_fetch_row(Result)) != NULL) {
    printf("id:%s\tage:%s\n", Row[0], Row[1]);
  }

  mysql_close(&ConnectPointer);
  printf("database connection closed successfully\n");
  printf("\n");
  return 0;
}
