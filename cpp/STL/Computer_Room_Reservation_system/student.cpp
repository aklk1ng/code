#include "student.h"
#include "globalFile.h"
#include <cstdlib>
#include <fstream>
#include <vector>
Student::Student() {}

Student::Student(int id, string name, string pwd) {
    this->m_Id = id;
    this->m_name = name;
    this->m_pwd = pwd;
    this->initComputer();
}

void Student::initComputer() {
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);
    ComputerRoom com;
    while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) {
        vCom.push_back(com);
    }
    ifs.close();
}
void Student::operMenu() {
    cout << "Welcome! " << this->m_name << endl;
    cout << "\t\t------------------------\n";
    cout << "\t\t|                      |\n";
    cout << "\t\t|     1.apply order    |\n";
    cout << "\t\t|                      |\n";
    cout << "\t\t|    2.check orders    |\n";
    cout << "\t\t|                      |\n";
    cout << "\t\t|  3.check all orders  |\n";
    cout << "\t\t|                      |\n";
    cout << "\t\t|    4.cancel orders   |\n";
    cout << "\t\t|                      |\n";
    cout << "\t\t|      0.logout        |\n";
    cout << "\t\t|                      |\n";
    cout << "\t\t------------------------\n";
    cout << "Please enter your choice: ";
}

void Student::applyOrder() {
    cout << "1.Monday" << endl;
    cout << "2.Tuesday" << endl;
    cout << "3.Wednessay" << endl;
    cout << "4.Thursday" << endl;
    cout << "5.Friday" << endl;

    int date = 0;
    int interval = 0;
    int room = 0;

    while (1) {
        cin >> date;
        if (date >= 1 && date <= 5) {
            break;
        }
        cout << "The select is wrong!Please enter again: " << endl;
    }
    cout << "Please enter the time:" << endl;
    cout << "1.morning" << endl;
    cout << "2.evening" << endl;
    while (1) {
        cin >> interval;
        if (interval >= 1 && interval <= 2) {
            break;
        }
        cout << "The select is wrong!Please enter again: " << endl;
    }
    cout << "Please enter the computer room:" << endl;
    for (int i = 0; i < vCom.size(); i++) {
        cout << "ComputerID: " << vCom[i].m_ComId
             << "\tComputerCapacity: " << vCom[i].m_MaxNum << endl;
    }
    while (1) {
        cin >> room;
        if (room >= 1 && room <= 3) {
            break;
        }
        cout << "The select is wrong!Please enter again: " << endl;
    }
    cout << "order successfully!" << endl;

    ofstream ofs;
    ofs.open(ORDER_FILE, ios::app);
    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stuID:" << this->m_Id << " ";
    ofs << "stuName:" << this->m_name << " ";
    ofs << "room:" << room << " ";
    ofs << "status:" << 1 << endl;
    ofs.close();
}

void Student::showOrder() {
    OrderFile of;
    if (of.m_Size == 0) {
        cout << "the orders is empty!" << endl;
        return;
    }
    for (int i = 0; i < of.m_Size; i++) {
        if (atoi(of.m_orderData[i]["stuID"].c_str()) == this->m_Id) {
            cout << "Order date:" << of.m_orderData[i]["date"] << "\t";
            cout << "Order time:"
                 << (of.m_orderData[i]["interval"] == "1" ? "morning"
                                                          : "evening")
                 << "\t";
            cout << "Order room:" << of.m_orderData[i]["room"] << "\t";
            string status = "Status:";
            if (of.m_orderData[i]["status"] == "1") {
                status += "under review";
            } else if (of.m_orderData[i]["status"] == "2") {
                status += "examination passed";
            } else if (of.m_orderData[i]["status"] == "-1") {
                status += "review failed";
            } else
                status += "cancel review";
            cout << status << endl;
        }
    }
}

void Student::showAllOrder() {
    OrderFile of;
    if (of.m_Size == 0) {
        cout << "the orders is empty!" << endl;
        return;
    }
    for (int i = 0; i < of.m_Size; i++) {
        cout << i + 1 << ", ";
        if (atoi(of.m_orderData[i]["stuID"].c_str()) == this->m_Id) {
            cout << "Order date:" << of.m_orderData[i]["date"] << "\t";
            cout << "Order time:"
                 << (of.m_orderData[i]["interval"] == "1" ? "morning"
                                                          : "evening")
                 << "\t";
            cout << "stuID:" << of.m_orderData[i]["stuID"] << "\t";
            cout << "StuName:" << of.m_orderData[i]["stuName"] << "\t";
            cout << "Order room:" << of.m_orderData[i]["room"] << "\t";
            string status = "Status:";
            if (of.m_orderData[i]["status"] == "1") {
                status += "under review";
            } else if (of.m_orderData[i]["status"] == "2") {
                status += "examination passed";
            } else if (of.m_orderData[i]["status"] == "-1") {
                status += "review failed";
            } else
                status += "cancel review";
            cout << status << endl;
        }
    }
}

void Student::cancelOrder() {
    OrderFile of;
    if (of.m_Size == 0) {
        cout << "the orders is empty!" << endl;
        return;
    }
    cout << "Please enter your choice" << endl;
    vector<int> v;
    int index = 1;
    for (int i = 0; i < of.m_Size; i++) {
        if (atoi(of.m_orderData[i]["stuID"].c_str()) == this->m_Id) {
            if (of.m_orderData[i]["status"] == "1" ||
                of.m_orderData[i]["status"] == "2") {
                v.push_back(i);
                cout << index++ << ". ";
                cout << "Order date:" << of.m_orderData[i]["date"] << "\t";
                cout << "Order time:"
                     << (of.m_orderData[i]["interval"] == "1" ? "morning"
                                                              : "evening")
                     << "\t";
                cout << "Order room:" << of.m_orderData[i]["room"] << "\t";
                string status = "Status:";
                if (of.m_orderData[i]["status"] == "1") {
                    status += "under review";
                } else if (of.m_orderData[i]["status"] == "2") {
                    status += "examination passed";
                } else if (of.m_orderData[i]["status"] == "-1") {
                    status += "review failed";
                } else
                    status += "cancel review";
                cout << status << endl;
            }
        }
    }
    cout << "Please enter your choice, 0 is return" << endl;
    int select = 0;
    while (1) {
        cin >> select;
        if (select >= 0 && select <= v.size()) {
            if (select == 0) {
                break;
            } else {
                of.m_orderData[v[select - 1]]["status"] = "0";
                of.updateOrder();
                cout << "cancel successfully!" << endl;
                break;
            }
        }
        cout << "the choice is wrong,please enter again!" << endl;
    }
}
