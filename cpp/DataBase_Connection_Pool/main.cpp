#include "MysqlConn.h"
#include <iostream>
#include <memory>
using namespace std;

int query() {
  MysqlConn conn;
  conn.connect("root", "1234", "test", "47.107.238.143");
  string sql = "insert into student(id, name) values(3, 'cjh')";
  bool flag = conn.update(sql);
  cout << flag << endl;
  sql = "select * from student";
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
