#include "globalFile.h"
#include "student.h"
#include <fstream>
#include <vector>

Student::Student() {}

Student::Student(int id, std::string name, std::string pwd) {
  this->m_Id = id;
  this->m_name = name;
  this->m_pwd = pwd;
  this->initComputer();
}

void Student::initComputer() {
  std::ifstream ifs;
  ifs.open(COMPUTER_FILE, std::ios::in);
  ComputerRoom com;
  while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) {
    vCom.push_back(com);
  }
  ifs.close();
}

void Student::operMenu() {
  std::cout << "Welcome! " << this->m_name << std::endl;
  std::cout << "\t\t------------------------\n";
  std::cout << "\t\t|                      |\n";
  std::cout << "\t\t|     1.apply order    |\n";
  std::cout << "\t\t|                      |\n";
  std::cout << "\t\t|    2.check orders    |\n";
  std::cout << "\t\t|                      |\n";
  std::cout << "\t\t|  3.check all orders  |\n";
  std::cout << "\t\t|                      |\n";
  std::cout << "\t\t|    4.cancel orders   |\n";
  std::cout << "\t\t|                      |\n";
  std::cout << "\t\t|      0.logout        |\n";
  std::cout << "\t\t|                      |\n";
  std::cout << "\t\t------------------------\n";
  std::cout << "Please enter your choice: ";
}

void Student::applyOrder() {
  std::cout << "1.Monday" << std::endl;
  std::cout << "2.Tuesday" << std::endl;
  std::cout << "3.Wednessay" << std::endl;
  std::cout << "4.Thursday" << std::endl;
  std::cout << "5.Friday" << std::endl;

  int date = 0;
  int interval = 0;
  int room = 0;

  while (1) {
    std::cin >> date;
    if (date >= 1 && date <= 5) {
      break;
    }
    std::cout << "The select is wrong!Please enter again: " << std::endl;
  }
  std::cout << "Please enter the time:" << std::endl;
  std::cout << "1.morning" << std::endl;
  std::cout << "2.evening" << std::endl;
  while (1) {
    std::cin >> interval;
    if (interval >= 1 && interval <= 2) {
      break;
    }
    std::cout << "The select is wrong!Please enter again: " << std::endl;
  }
  std::cout << "Please enter the computer room:" << std::endl;
  for (int i = 0; i < vCom.size(); i++) {
    std::cout << "ComputerID: " << vCom[i].m_ComId
              << "\tComputerCapacity: " << vCom[i].m_MaxNum << std::endl;
  }
  while (1) {
    std::cin >> room;
    if (room >= 1 && room <= 3) {
      break;
    }
    std::cout << "The select is wrong!Please enter again: " << std::endl;
  }
  std::cout << "order successfully!" << std::endl;

  std::ofstream ofs;
  ofs.open(ORDER_FILE, std::ios::app);
  ofs << "date:" << date << " ";
  ofs << "interval:" << interval << " ";
  ofs << "stuID:" << this->m_Id << " ";
  ofs << "stuName:" << this->m_name << " ";
  ofs << "room:" << room << " ";
  ofs << "status:" << 1 << std::endl;
  ofs.close();
}

void Student::showOrder() {
  OrderFile of;
  if (of.m_Size == 0) {
    std::cout << "the orders is empty!" << std::endl;
    return;
  }
  for (int i = 0; i < of.m_Size; i++) {
    if (atoi(of.m_orderData[i]["stuID"].c_str()) == this->m_Id) {
      std::cout << "Order date:" << of.m_orderData[i]["date"] << "\t";
      std::cout << "Order time:"
                << (of.m_orderData[i]["interval"] == "1" ? "morning"
                                                         : "evening")
                << "\t";
      std::cout << "Order room:" << of.m_orderData[i]["room"] << "\t";
      std::string status = "Status:";
      if (of.m_orderData[i]["status"] == "1") {
        status += "under review";
      } else if (of.m_orderData[i]["status"] == "2") {
        status += "examination passed";
      } else if (of.m_orderData[i]["status"] == "-1") {
        status += "review failed";
      } else
        status += "cancel review";
      std::cout << status << std::endl;
    }
  }
}

void Student::showAllOrder() {
  OrderFile of;
  if (of.m_Size == 0) {
    std::cout << "the orders is empty!" << std::endl;
    return;
  }
  for (int i = 0; i < of.m_Size; i++) {
    std::cout << i + 1 << ", ";
    if (atoi(of.m_orderData[i]["stuID"].c_str()) == this->m_Id) {
      std::cout << "Order date:" << of.m_orderData[i]["date"] << "\t";
      std::cout << "Order time:"
                << (of.m_orderData[i]["interval"] == "1" ? "morning"
                                                         : "evening")
                << "\t";
      std::cout << "stuID:" << of.m_orderData[i]["stuID"] << "\t";
      std::cout << "StuName:" << of.m_orderData[i]["stuName"] << "\t";
      std::cout << "Order room:" << of.m_orderData[i]["room"] << "\t";
      std::string status = "Status:";
      if (of.m_orderData[i]["status"] == "1") {
        status += "under review";
      } else if (of.m_orderData[i]["status"] == "2") {
        status += "examination passed";
      } else if (of.m_orderData[i]["status"] == "-1") {
        status += "review failed";
      } else
        status += "cancel review";
      std::cout << status << std::endl;
    }
  }
}

void Student::cancelOrder() {
  OrderFile of;
  if (of.m_Size == 0) {
    std::cout << "the orders is empty!" << std::endl;
    return;
  }
  std::cout << "Please enter your choice" << std::endl;
  std::vector<int> v;
  int index = 1;
  for (int i = 0; i < of.m_Size; i++) {
    if (atoi(of.m_orderData[i]["stuID"].c_str()) == this->m_Id) {
      if (of.m_orderData[i]["status"] == "1" ||
          of.m_orderData[i]["status"] == "2") {
        v.push_back(i);
        std::cout << index++ << ". ";
        std::cout << "Order date:" << of.m_orderData[i]["date"] << "\t";
        std::cout << "Order time:"
                  << (of.m_orderData[i]["interval"] == "1" ? "morning"
                                                           : "evening")
                  << "\t";
        std::cout << "Order room:" << of.m_orderData[i]["room"] << "\t";
        std::string status = "Status:";
        if (of.m_orderData[i]["status"] == "1") {
          status += "under review";
        } else if (of.m_orderData[i]["status"] == "2") {
          status += "examination passed";
        } else if (of.m_orderData[i]["status"] == "-1") {
          status += "review failed";
        } else
          status += "cancel review";
        std::cout << status << std::endl;
      }
    }
  }
  std::cout << "Please enter your choice, 0 is return" << std::endl;
  int select = 0;
  while (1) {
    std::cin >> select;
    if (select >= 0 && select <= v.size()) {
      if (select == 0) {
        break;
      } else {
        of.m_orderData[v[select - 1]]["status"] = "0";
        of.updateOrder();
        std::cout << "cancel successfully!" << std::endl;
        break;
      }
    }
    std::cout << "the choice is wrong,please enter again!" << std::endl;
  }
}
