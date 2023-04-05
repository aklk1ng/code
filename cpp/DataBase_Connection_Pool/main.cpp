#include "MysqlConn.h"
#include <iostream>
#include <memory>
using namespace std;

int query() {
  MysqlConn conn;
  conn.connect("root", "@JMYchenjinhui6", "test", "114.132.159.164");
  string sql = "insert into test_create values(3, 'ooo', 10, 1)";
  bool flag = conn.update(sql);
  cout << flag << endl;
  sql = "select * from test_create";
  conn.query(sql);
  while (conn.next()) {
    cout << conn.value(0) << "," << conn.value(1) << endl;
  }
  return 0;
}

int main(int argc, char *argv[]) {
  query();
  return 0;
}
