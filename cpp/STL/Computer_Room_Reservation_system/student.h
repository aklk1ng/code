#pragma once
#include "Computer_Room_Reservation.h"
#include "Identity.h"
#include "computerRoom.h"
#include "orderFile.h"
#include <vector>

class Student : public Identity {
public:
  Student();
  Student(int id, std::string name, std::string pwd);
  virtual void operMenu();

  void initComputer();
  void applyOrder();
  void showOrder();
  void showAllOrder();
  void cancelOrder();
  int m_Id;
  std::vector<ComputerRoom> vCom;
};
