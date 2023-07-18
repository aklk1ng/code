#include "computerRoom.h"
#include "globalFile.h"
#include "manager.h"
#include "student.h"
#include "teacher.h"
#include <fstream>
#include <vector>
Manager::Manager() {}

Manager::Manager(string name, string pwd) {
  this->m_name = name;
  this->m_pwd = pwd;
  this->initVector();
  this->initComputer();
}

void Manager::operMenu() {
  cout << "Welcome! " << this->m_name << endl;
  cout << "\t\t------------------------\n";
  cout << "\t\t|                      |\n";
  cout << "\t\t|     1.add account    |\n";
  cout << "\t\t|                      |\n";
  cout << "\t\t|    2.check account   |\n";
  cout << "\t\t|                      |\n";
  cout << "\t\t|    3.check computer  |\n";
  cout << "\t\t|                      |\n";
  cout << "\t\t|    4.empty orders    |\n";
  cout << "\t\t|                      |\n";
  cout << "\t\t|      0.logout        |\n";
  cout << "\t\t|                      |\n";
  cout << "\t\t------------------------\n";
  cout << "Please enter your choice: ";
}

bool Manager::checkRepeat(int id, int type) {
  if (type == 1) {
    for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
      if (id == it->m_Id) {
        return true;
      }
    }
  } else {
    for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
      if (id == it->m_EmpId) {
        return true;
      }
    }
  }
  return false;
}

void Manager::initVector() {
  ifstream ifs;
  ifs.open(STUDENT_FILE, ios::in);
  if (!ifs.is_open()) {
    cout << "read the file failed!" << endl;
    return;
  }
  vStu.clear();
  vTea.clear();

  Student s;
  while (ifs >> s.m_Id && ifs >> s.m_name && ifs >> s.m_pwd) {
    vStu.push_back(s);
  }
  cout << "the number of students currently: " << vStu.size() << endl;
  ifs.close();

  ifs.open(TEACHER_FILE, ios::in);
  Teacher t;
  while (ifs >> t.m_EmpId && ifs >> t.m_name && ifs >> t.m_pwd) {
    vTea.push_back(t);
  }
  cout << "the number of teachers currently: " << vTea.size() << endl;
  ifs.close();
}

void Manager::initComputer() {
  ifstream ifs;
  ifs.open(COMPUTER_FILE, ios::in);
  ComputerRoom com;
  while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) {
    vCom.push_back(com);
  }
  ifs.close();
}

void Manager::addPerson() {
  cout << "Please enter the account type" << endl;
  cout << "1.student" << endl;
  cout << "2.teacher" << endl;

  string fileName;
  string tip; // show the id
  string errorTip;
  ofstream ofs;

  int select = 0;
  cin >> select;
  if (select == 1) {
    fileName = STUDENT_FILE;
    tip = "Please enter student ID: ";
    errorTip = "the student ID is repeated,please enter again:";
  } else if (select == 2) {
    fileName = TEACHER_FILE;
    tip = "Please enter teacher ID: ";
    errorTip = "the teacher ID is repeated,please enter again:";
  }

  ofs.open(fileName, ios::out | ios::app);
  int id;
  string name;
  string pwd;
  cout << tip << endl;
  while (1) {
    cin >> id;
    bool ret = checkRepeat(id, select);
    if (ret) {
      cout << errorTip << endl;
    } else
      break;
  }

  cout << "Please enter the name: ";
  cin >> name;
  cout << "Please enter the pwd: ";
  cin >> pwd;
  ofs << id << " " << name << " " << pwd << endl;
  cout << "add sucessfully!" << endl;
  ofs.close();
  this->initVector();
}

void Manager::showPerson() {
  cout << "Please select the content" << endl;
  cout << "1.students" << endl;
  cout << "2.teachers" << endl;
  int select = 0;
  cin >> select;
  if (select == 1) {
    for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
      cout << "ID: " << it->m_Id << "\tName: " << it->m_name << "\tPassword:" << it->m_pwd << endl;
    }
  } else {
    for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
      cout << "ID: " << it->m_EmpId << "\tName: " << it->m_name << "\tPassword:" << it->m_pwd
           << endl;
    }
  }
}

void Manager::showComputer() {
  cout << "The computer room information:" << endl;
  for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {
    cout << "ComputerID: " << it->m_ComId << "\tComputerCapacuty: " << it->m_MaxNum << endl;
  }
}

void Manager::cleanFile() {
  ofstream ofs(ORDER_FILE, ios::trunc);
  ofs.close();
  cout << "clean sucessfully!" << endl;
}
