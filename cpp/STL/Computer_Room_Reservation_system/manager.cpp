#include "computerRoom.h"
#include "globalFile.h"
#include "manager.h"
#include "student.h"
#include "teacher.h"
#include <fstream>
#include <vector>

Manager::Manager() {}

Manager::Manager(std::string name, std::string pwd) {
  this->m_name = name;
  this->m_pwd = pwd;
  this->initVector();
  this->initComputer();
}

void Manager::operMenu() {
  std::cout << "Welcome! " << this->m_name << std::endl;
  std::cout << "\t\t------------------------\n";
  std::cout << "\t\t|                      |\n";
  std::cout << "\t\t|     1.add account    |\n";
  std::cout << "\t\t|                      |\n";
  std::cout << "\t\t|    2.check account   |\n";
  std::cout << "\t\t|                      |\n";
  std::cout << "\t\t|    3.check computer  |\n";
  std::cout << "\t\t|                      |\n";
  std::cout << "\t\t|    4.empty orders    |\n";
  std::cout << "\t\t|                      |\n";
  std::cout << "\t\t|      0.logout        |\n";
  std::cout << "\t\t|                      |\n";
  std::cout << "\t\t------------------------\n";
  std::cout << "Please enter your choice: ";
}

bool Manager::checkRepeat(int id, int type) {
  if (type == 1) {
    for (std::vector<Student>::iterator it = vStu.begin(); it != vStu.end();
         it++) {
      if (id == it->m_Id) {
        return true;
      }
    }
  } else {
    for (std::vector<Teacher>::iterator it = vTea.begin(); it != vTea.end();
         it++) {
      if (id == it->m_EmpId) {
        return true;
      }
    }
  }
  return false;
}

void Manager::initVector() {
  std::ifstream ifs;
  ifs.open(STUDENT_FILE, std::ios::in);
  if (!ifs.is_open()) {
    std::cout << "read the file failed!" << std::endl;
    return;
  }
  vStu.clear();
  vTea.clear();

  Student s;
  while (ifs >> s.m_Id && ifs >> s.m_name && ifs >> s.m_pwd) {
    vStu.push_back(s);
  }
  std::cout << "the number of students currently: " << vStu.size() << std::endl;
  ifs.close();

  ifs.open(TEACHER_FILE, std::ios::in);
  Teacher t;
  while (ifs >> t.m_EmpId && ifs >> t.m_name && ifs >> t.m_pwd) {
    vTea.push_back(t);
  }
  std::cout << "the number of teachers currently: " << vTea.size() << std::endl;
  ifs.close();
}

void Manager::initComputer() {
  std::ifstream ifs;
  ifs.open(COMPUTER_FILE, std::ios::in);
  ComputerRoom com;
  while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) {
    vCom.push_back(com);
  }
  ifs.close();
}

void Manager::addPerson() {
  std::cout << "Please enter the account type" << std::endl;
  std::cout << "1.student" << std::endl;
  std::cout << "2.teacher" << std::endl;

  std::string fileName;
  std::string tip; // show the id
  std::string errorTip;
  std::ofstream ofs;

  int select = 0;
  std::cin >> select;
  if (select == 1) {
    fileName = STUDENT_FILE;
    tip = "Please enter student ID: ";
    errorTip = "the student ID is repeated,please enter again:";
  } else if (select == 2) {
    fileName = TEACHER_FILE;
    tip = "Please enter teacher ID: ";
    errorTip = "the teacher ID is repeated,please enter again:";
  }

  ofs.open(fileName, std::ios::out | std::ios::app);
  int id;
  std::string name;
  std::string pwd;
  std::cout << tip << std::endl;
  while (1) {
    std::cin >> id;
    bool ret = checkRepeat(id, select);
    if (ret) {
      std::cout << errorTip << std::endl;
    } else
      break;
  }

  std::cout << "Please enter the name: ";
  std::cin >> name;
  std::cout << "Please enter the pwd: ";
  std::cin >> pwd;
  ofs << id << " " << name << " " << pwd << std::endl;
  std::cout << "add sucessfully!" << std::endl;
  ofs.close();
  this->initVector();
}

void Manager::showPerson() {
  std::cout << "Please select the content" << std::endl;
  std::cout << "1.students" << std::endl;
  std::cout << "2.teachers" << std::endl;
  int select = 0;
  std::cin >> select;
  if (select == 1) {
    for (std::vector<Student>::iterator it = vStu.begin(); it != vStu.end();
         it++) {
      std::cout << "ID: " << it->m_Id << "\tName: " << it->m_name
                << "\tPassword:" << it->m_pwd << std::endl;
    }
  } else {
    for (std::vector<Teacher>::iterator it = vTea.begin(); it != vTea.end();
         it++) {
      std::cout << "ID: " << it->m_EmpId << "\tName: " << it->m_name
                << "\tPassword:" << it->m_pwd << std::endl;
    }
  }
}

void Manager::showComputer() {
  std::cout << "The computer room information:" << std::endl;
  for (std::vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end();
       it++) {
    std::cout << "ComputerID: " << it->m_ComId
              << "\tComputerCapacuty: " << it->m_MaxNum << std::endl;
  }
}

void Manager::cleanFile() {
  std::ofstream ofs(ORDER_FILE, std::ios::trunc);
  ofs.close();
  std::cout << "clean sucessfully!" << std::endl;
}
