#pragma once
#include <chrono>
#include <iostream>
#include <mysql/mysql.h>
using namespace std::chrono;

class MysqlConn {
public:
  // init the database connection
  MysqlConn();
  // free the database connection
  ~MysqlConn();
  // connect the database
  bool connect(std::string user, std::string passwd, std::string dbName,
               std::string ip, unsigned short int port = 3306);
  // update the database
  bool update(std::string sql);
  // query database
  bool query(std::string sql);
  // traverse result
  bool next();
  // get result's fields
  std::string value(int index);
  // transaction operate
  bool transaction();
  // submit transaction
  bool commmit();
  // rollback transaction
  bool rollback();
  // refresh the free time
  void refreshAliveTime();
  // get the connection total time
  long long getAliveTime();

private:
  void freeResult();
  MYSQL *m_conn = nullptr;
  MYSQL_RES *m_result = nullptr;
  MYSQL_ROW m_row = nullptr;
  steady_clock::time_point m_alivetime;
};
