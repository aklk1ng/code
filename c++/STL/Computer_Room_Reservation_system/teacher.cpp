#include "teacher.h"
#include "Computer_Room_Reservation.h"
#include "orderFile.h"

Teacher::Teacher() {}
Teacher::Teacher(int empId, string name, string pwd) {
    this->m_EmpId = empId;
    this->m_name = name;
    this->m_pwd = pwd;
}
void Teacher::operMenu() {
    cout << "Welcome! " << this->m_name << endl;
    cout << "\t\t------------------------\n";
    cout << "\t\t|                      |\n";
    cout << "\t\t|  1.check all orders  |\n";
    cout << "\t\t|                      |\n";
    cout << "\t\t|    2.review orders   |\n";
    cout << "\t\t|                      |\n";
    cout << "\t\t|      0.logout        |\n";
    cout << "\t\t|                      |\n";
    cout << "\t\t------------------------\n";
    cout << "Please enter your choice: ";
}
void Teacher::showAllOrder() {
    OrderFile of;
    if (of.m_Size == 0) {
        cout << "the orders is empty!" << endl;
        return;
    }
    for (int i = 0; i < of.m_Size; i++) {
        cout << "Order date:" << of.m_orderData[i]["date"] << "\t";
        cout << "Order time:"
             << (of.m_orderData[i]["interval"] == "1" ? "morning" : "evening")
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
void Teacher::validOrder() {
    OrderFile of;
    if (of.m_Size == 0) {
        cout << "the orders is empty!" << endl;
        return;
    }
    vector<int> v;
    int index = 1;
    cout << "the orders:" << endl;
    for (int i = 0; i < of.m_Size; i++) {
        if (of.m_orderData[i]["status"] == "1") {
            v.push_back(i);
            cout << index++ << ". ";
            cout << "Order date:" << of.m_orderData[i]["date"] << "\t";
            cout << "Order time:"
                 << (of.m_orderData[i]["interval"] == "1" ? "morning"
                                                          : "evening")
                 << "\t";
            cout << "Order room:" << of.m_orderData[i]["room"] << "\t";
            string status = "Status:under review";
            cout << status << endl;
        }
    }
    cout << "Please enter your choice, 0 is return" << endl;
    int select = 0;
    int ret = 0;
    while (1) {
        cin >> select;
        if (select >= 0 && select <= v.size()) {
            if (select == 0) {
                break;
            } else {
                cout << "Please enter the review result" << endl;
                cout << "1.pass" << endl;
                cout << "2.fail" << endl;
                cin >> ret;
                if (ret == 1) {
                    of.m_orderData[v[select - 1]]["status"] = "2";
                } else
                    of.m_orderData[v[select - 1]]["status"] = "-1";
            }
            of.updateOrder();
            cout << "review over!" << endl;
            break;
        }
        cout << "the choice is wrong,please enter again!" << endl;
    }
}
