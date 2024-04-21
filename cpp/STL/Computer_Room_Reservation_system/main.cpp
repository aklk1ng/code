#include "Identity.h"
#include "globalFile.h"
#include "manager.h"
#include "student.h"
#include "teacher.h"
#include <fstream>

void studentMenu(Identity *&student) {
  while (1) {
    student->operMenu();
    Student *stu = (Student *)student;
    int select = 0;
    std::cin >> select;

    if (select == 1) { // apply order
      stu->applyOrder();
    } else if (select == 2) { // check orders
      stu->showOrder();
    } else if (select == 3) { // check all orders
      stu->showAllOrder();
    } else if (select == 4) { // cancel orders
      stu->cancelOrder();
    } else { // logout
      delete student;
      std::cout << "Logout successfully!" << std::endl;
      return;
    }
  }
}

void teacherMenu(Identity *&teacher) {
  while (1) {
    teacher->operMenu();
    Teacher *tea = (Teacher *)teacher;
    int select = 0;
    std::cin >> select;
    if (select == 1) {
      tea->showAllOrder();
    } else if (select == 2) {
      tea->validOrder();
    } else {
      delete teacher;
      std::cout << "Logout" << std::endl;
      return;
    }
  }
}

void managerMenu(Identity *&manager) {
  while (1) {
    manager->operMenu();
    Manager *man = (Manager *)manager;
    int select = 0;
    std::cin >> select;
    if (select == 1) { // add account
      man->addPerson();
    } else if (select == 2) { // check account
      man->showPerson();
    } else if (select == 3) { // check computer room
      man->showComputer();
    } else if (select == 4) { // empty reserves
      man->cleanFile();
    } else {
      delete manager;
      std::cout << "Logout successfuly!" << std::endl;
      return;
    }
  }
}

void LoginIn(std::string filename, int type) {
  Identity *person = NULL;
  std::ifstream ifs;
  ifs.open(filename, std::ios::in);
  if (!ifs.is_open()) {
    std::cout << "the file isn't exist!" << std::endl;
    ifs.close();
    return;
  }
  int id = 0;
  std::string name;
  std::string pwd;

  // verify the login
  if (type == 1) {
    std::cout << "Please enter your student ID: ";
    std::cin >> id;
  } else if (type == 2) {
    std::cout << "Please enter your teacher ID: ";
    std::cin >> id;
  }
  std::cout << "Please enter your name: ";
  std::cin >> name;

  std::cout << "Please enter your password: ";
  std::cin >> pwd;

  if (type == 1) {
    int fId;
    std::string fName;
    std::string fPwd;
    while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
      if (id == fId && name == fName && pwd == fPwd) {
        std::cout << "Student verify successfully!" << std::endl;
        person = new Student(id, name, pwd);
        studentMenu(person);
        return;
      }
    }
  } else if (type == 2) {
    int fId;
    std::string fName;
    std::string fPwd;
    while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
      if (id == fId && name == fName && pwd == fPwd) {
        std::cout << "Teacher verify successfully!" << std::endl;
        person = new Teacher(id, name, pwd);
        teacherMenu(person);
        return;
      }
    }
  } else if (type == 3) {
    std::string fName;
    std::string fPwd;
    while (ifs >> fName && ifs >> fPwd) {
      if (name == fName && pwd == fPwd) {
        std::cout << "Teacher verify successfully!" << std::endl;
        person = new Manager(name, pwd);
        managerMenu(person);
        return;
      }
    }
  }
  std::cout << "Login failed!" << std::endl;
  return;
}

int main(int argc, char *argv[]) {
  int select = 0;
  std::cout << "Please enter your identity" << std::endl;
  std::cout << "\t\t------------------------\n";
  std::cout << "\t\t|                      |\n";
  std::cout << "\t\t|      1.Student       |\n";
  std::cout << "\t\t|                      |\n";
  std::cout << "\t\t|      2.Teacher       |\n";
  std::cout << "\t\t|                      |\n";
  std::cout << "\t\t|      3.Manager       |\n";
  std::cout << "\t\t|                      |\n";
  std::cout << "\t\t|      0.Exit          |\n";
  std::cout << "\t\t|                      |\n";
  std::cout << "\t\t------------------------\n";
  std::cout << "Please enter your choice: ";
  std::cin >> select;
  switch (select) {
  case 1:
    LoginIn(STUDENT_FILE, 1);
    break;
  case 2:
    LoginIn(TEACHER_FILE, 2);
    break;
  case 3:
    LoginIn(ADMIN_FILE, 3);
    break;
  case 0:
    std::cout << "See you again!" << std::endl;
    return 0;
    break;
  default:
    std::cout << "The choice is wrong!" << std::endl;
    break;
  }
  return 0;
}
