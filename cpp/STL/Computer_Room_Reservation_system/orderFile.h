#pragma once
#include "Computer_Room_Reservation.h"
#include <fstream>
#include <map>
#include <string>

class OrderFile {
public:
  OrderFile();
  void updateOrder();
  std::map<int, std::map<std::string, std::string>> m_orderData;
  int m_Size;
};
