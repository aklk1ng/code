#include "MysqlConn.h"
#include <iostream>

int query() {
    MysqlConn conn;
    conn.connect("root", "@JMYchenjinhui6", "test", "114.132.159.164");
    std::string sql = "insert into test_create values(3, 'ooo', 10, 1)";
    bool flag = conn.update(sql);
    std::cout << flag << std::endl;
    sql = "select * from test_create";
    conn.query(sql);
    while (conn.next()) {
        std::cout << conn.value(0) << "," << conn.value(1) << '\n';
    }
    return 0;
}

int main(int argc, char *argv[]) {
    query();
    return 0;
}
