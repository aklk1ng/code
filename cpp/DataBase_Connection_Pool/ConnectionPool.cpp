#include "ConnectionPool.h"
#include "MysqlConn.h"
#include <chrono>
#include <condition_variable>
#include <fstream>
#include <json/json.h>
#include <memory>
#include <mutex>
#include <thread>
using namespace Json;

void ConnectionPool::addConnection() {
    MysqlConn *conn = new MysqlConn;
    conn->connect(m_user, m_passwd, m_dbName, m_ip, m_port);
    m_connectionQ.push(conn);
}

ConnectionPool *ConnectionPool::getConnectPool() {
    static ConnectionPool pool;
    return &pool;
}

std::shared_ptr<MysqlConn> ConnectionPool::getConnection() {
    std::unique_lock<std::mutex> locker(m_mutexQ);
    while (m_connectionQ.empty()) {
        if (std::cv_status::timeout ==
            m_cond.wait_for(locker, std::chrono::milliseconds(m_timeout))) {
            if (m_connectionQ.empty()) {
                continue;
            }
        }
    }
    std::shared_ptr<MysqlConn> connptr(
        m_connectionQ.front(), [this](MysqlConn *conn) {
            /* m_mutexQ.lock(); */
            std::lock_guard<std::mutex> locker(m_mutexQ);
            conn->refreshAliveTime();
            m_connectionQ.push(conn);
            /* m_mutexQ.unlock(); */
        });
    m_connectionQ.pop();
    m_cond.notify_all();
    return connptr;
}

bool ConnectionPool::parseJsonFile() {
    std::ifstream ifs("dbcout.json");
    Reader rd;
    Value root;
    rd.parse(ifs, root);
    if (root.isObject()) {
        m_ip = root["ip"].asString();
        m_port = root["port"].asInt();
        m_user = root["userName"].asString();
        m_passwd = root["password"].asString();
        m_dbName = root["dbName"].asString();
        m_minSize = root["minSize"].asInt();
        m_maxSize = root["maxSize"].asInt();
        m_maxIdleTime = root["maxIdleTime"].asInt();
        m_timeout = root["timeout"].asInt();
        return true;
    }
    return false;
}

void ConnectionPool::producerConnection() {
    while (true) {
        std::unique_lock<std::mutex> locker(m_mutexQ);
        while (m_connectionQ.size() >= m_minSize) {
            m_cond.wait(locker);
        }
        addConnection();
        m_cond.notify_all();
    }
}

void ConnectionPool::recyclerConnection() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::lock_guard<std::mutex> locker(m_mutexQ);
        while (m_connectionQ.size() > m_minSize) {
            MysqlConn *conn = m_connectionQ.front();
            if (conn->getAliveTime() >= m_maxIdleTime) {
                m_connectionQ.pop();
                delete conn;
            } else {
                break;
            }
        }
    }
}

ConnectionPool::ConnectionPool() {
    if (!parseJsonFile()) {
        return;
    }
    for (int i = 0; i < m_minSize; i++) {
        addConnection();
    }
    std::thread producer(&ConnectionPool::producerConnection, this);
    std::thread recycler(&ConnectionPool::recyclerConnection, this);
    producer.detach();
    recycler.detach();
}

ConnectionPool::~ConnectionPool() {
    while (!m_connectionQ.empty()) {
        MysqlConn *conn = m_connectionQ.front();
        m_connectionQ.pop();
        delete conn;
    }
}
