#pragma once
#include "Computer_Room_Reservation.h"

class Identity {
public:
  virtual void operMenu() = 0;
  std::string m_name;
  std::string m_pwd;
};
