#include "orderFile.h"
#include "teacher.h"

Teacher::Teacher() {}

Teacher::Teacher(int empId, std::string name, std::string pwd) {
  this->m_EmpId = empId;
  this->m_name = name;
  this->m_pwd = pwd;
}

void Teacher::operMenu() {
  std::cout << "Welcome! " << this->m_name << std::endl;
  std::cout << "\t\t------------------------\n";
  std::cout << "\t\t|                      |\n";
  std::cout << "\t\t|  1.check all orders  |\n";
  std::cout << "\t\t|                      |\n";
  std::cout << "\t\t|    2.review orders   |\n";
  std::cout << "\t\t|                      |\n";
  std::cout << "\t\t|      0.logout        |\n";
  std::cout << "\t\t|                      |\n";
  std::cout << "\t\t------------------------\n";
  std::cout << "Please enter your choice: ";
}

void Teacher::showAllOrder() {
  OrderFile of;
  if (of.m_Size == 0) {
    std::cout << "the orders is empty!" << std::endl;
    return;
  }
  for (int i = 0; i < of.m_Size; i++) {
    std::cout << "Order date:" << of.m_orderData[i]["date"] << "\t";
    std::cout << "Order time:"
              << (of.m_orderData[i]["interval"] == "1" ? "morning" : "evening")
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

void Teacher::validOrder() {
  OrderFile of;
  if (of.m_Size == 0) {
    std::cout << "the orders is empty!" << std::endl;
    return;
  }
  std::vector<int> v;
  int index = 1;
  std::cout << "the orders:" << std::endl;
  for (int i = 0; i < of.m_Size; i++) {
    if (of.m_orderData[i]["status"] == "1") {
      v.push_back(i);
      std::cout << index++ << ". ";
      std::cout << "Order date:" << of.m_orderData[i]["date"] << "\t";
      std::cout << "Order time:"
                << (of.m_orderData[i]["interval"] == "1" ? "morning"
                                                         : "evening")
                << "\t";
      std::cout << "Order room:" << of.m_orderData[i]["room"] << "\t";
      std::string status = "Status:under review";
      std::cout << status << std::endl;
    }
  }
  std::cout << "Please enter your choice, 0 is return" << std::endl;
  int select = 0;
  int ret = 0;
  while (1) {
    std::cin >> select;
    if (select >= 0 && select <= v.size()) {
      if (select == 0) {
        break;
      } else {
        std::cout << "Please enter the review result" << std::endl;
        std::cout << "1.pass" << std::endl;
        std::cout << "2.fail" << std::endl;
        std::cin >> ret;
        if (ret == 1) {
          of.m_orderData[v[select - 1]]["status"] = "2";
        } else
          of.m_orderData[v[select - 1]]["status"] = "-1";
      }
      of.updateOrder();
      std::cout << "review over!" << std::endl;
      break;
    }
    std::cout << "the choice is wrong,please enter again!" << std::endl;
  }
}
