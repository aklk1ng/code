#pragma once
#include "Computer_Room_Reservation.h"
#include "Identity.h"
#include "computerRoom.h"
#include "student.h"
#include "teacher.h"
#include <vector>

class Manager : public Identity {
public:
  Manager();
  Manager(std::string name, std::string pwd);
  virtual void operMenu();

  void addPerson();
  void initVector();
  void initComputer();
  bool checkRepeat(int id, int type);
  void showPerson();
  void showComputer();
  void cleanFile();

  std::vector<Student> vStu;
  std::vector<Teacher> vTea;
  std::vector<ComputerRoom> vCom;
};
