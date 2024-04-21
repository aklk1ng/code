#include "globalFile.h"
#include "orderFile.h"
#include <map>
#include <utility>

OrderFile::OrderFile() {
  std::ifstream ifs;
  ifs.open(ORDER_FILE, std::ios::in);
  std::string date;
  std::string interval;
  std::string stuID;
  std::string stuName;
  std::string roomID;
  std::string status;
  this->m_Size = 0;
  while (ifs >> date && ifs >> interval && ifs >> stuID && ifs >> stuName &&
         ifs >> roomID && ifs >> status) {
    std::string key;
    std::string value;
    std::map<std::string, std::string> m;
    int pos = date.find(":");
    if (pos != -1) {
      key = date.substr(0, pos);
      /* value = date.substr(pos+1); */
      value = date.substr(pos + 1, date.size() - pos - 1);
      m.insert(make_pair(key, value));
    }

    pos = interval.find(":");
    if (pos != -1) {
      key = interval.substr(0, pos);
      /* value = interval.substr(pos+1); */
      value = interval.substr(pos + 1, interval.size() - pos - 1);
      m.insert(make_pair(key, value));
    }

    pos = stuID.find(":");
    if (pos != -1) {
      key = stuID.substr(0, pos);
      /* value = stuID.substr(pos+1); */
      value = stuID.substr(pos + 1, stuID.size() - pos - 1);
      m.insert(make_pair(key, value));
    }

    pos = stuName.find(":");
    if (pos != -1) {
      key = stuName.substr(0, pos);
      /* value = stuName.substr(pos+1); */
      value = stuName.substr(pos + 1, stuName.size() - pos - 1);
      m.insert(make_pair(key, value));
    }

    pos = roomID.find(":");
    if (pos != -1) {
      key = roomID.substr(0, pos);
      /* value = roomID.substr(pos+1); */
      value = roomID.substr(pos + 1, roomID.size() - pos - 1);
      m.insert(make_pair(key, value));
    }

    pos = status.find(":");
    if (pos != -1) {
      key = status.substr(0, pos);
      /* value = status.substr(pos+1); */
      value = status.substr(pos + 1, status.size() - pos - 1);
      m.insert(make_pair(key, value));
    }

    this->m_orderData.insert(make_pair(this->m_Size, m));
    this->m_Size++;
  }
  ifs.close();
  /* for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it
   * != m_orderData.end(); it++) { */
  /*     cout << "num:" << it->first << "\tvalue:" << endl; */
  /*     for (map<string, string>::iterator i = (*it).second.begin(); i !=
   * (*it).second.end(); i++) { */
  /*         cout << "key:" << i->first << "\tvalue:" << i->second << endl; */
  /*     } */
  /* } */
}

void OrderFile::updateOrder() {
  if (this->m_Size == 0) {
    return;
  }
  std::ofstream ofs(ORDER_FILE, std::ios::out | std::ios::trunc);
  for (int i = 0; i < m_Size; i++) {
    ofs << "date:" << this->m_orderData[i]["date"] << " ";
    ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
    ofs << "stuID:" << this->m_orderData[i]["stuID"] << " ";
    ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
    ofs << "room:" << this->m_orderData[i]["room"] << " ";
    ofs << "status:" << this->m_orderData[i]["status"] << std::endl;
  }
  ofs.close();
}
