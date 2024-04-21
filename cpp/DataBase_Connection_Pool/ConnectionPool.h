#pragma once
#include "MysqlConn.h"
#include <condition_variable>
#include <memory>
#include <mutex>
#include <queue>

class ConnectionPool {
public:
  static ConnectionPool *getConnectPool();
  ConnectionPool(const ConnectionPool &obj) = delete;
  ConnectionPool &operator=(const ConnectionPool &obj) = delete;
  std::shared_ptr<MysqlConn> getConnection();
  ~ConnectionPool();

private:
  ConnectionPool();
  bool parseJsonFile();
  void producerConnection();
  void recyclerConnection();
  void addConnection();

  std::string m_ip;
  std::string m_user;
  std::string m_passwd;
  std::string m_dbName;
  unsigned short m_port;
  int m_minSize;
  int m_maxSize;
  int m_timeout;
  int m_maxIdleTime;
  std::queue<MysqlConn *> m_connectionQ;
  std::mutex m_mutexQ;
  std::condition_variable m_cond;
};
