#pragma once
#include "Computer_Room_Reservation.h"
#include "Identity.h"

class Teacher : public Identity {
public:
  Teacher();
  Teacher(int empId, std::string name, std::string pwd);
  virtual void operMenu();
  void showAllOrder();
  void validOrder();

  int m_EmpId;
};
