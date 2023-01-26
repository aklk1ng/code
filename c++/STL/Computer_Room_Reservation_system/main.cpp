#include "Computer_Room_Reservation.h"
#include "Identity.h"
#include "globalFile.h"
#include "manager.h"
#include "student.h"
#include "teacher.h"
#include <fstream>
using namespace std;

void studentMenu(Identity *&student) {
    while (1) {
        student->operMenu();
        Student *stu = (Student *)student;
        int select = 0;
        cin >> select;

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
            cout << "Logout successfully!" << endl;
            return;
        }
    }
}

void teacherMenu(Identity *&teacher) {
    while (1) {
        teacher->operMenu();
        Teacher *tea = (Teacher *)teacher;
        int select = 0;
        cin >> select;
        if (select == 1) {
            tea->showAllOrder();
        } else if (select == 2) {
            tea->validOrder();
        } else {
            delete teacher;
            cout << "Logout" << endl;
            return;
        }
    }
}

void managerMenu(Identity *&manager) {
    while (1) {
        manager->operMenu();
        Manager *man = (Manager *)manager;
        int select = 0;
        cin >> select;
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
            cout << "Logout successfuly!" << endl;
            return;
        }
    }
}

void LoginIn(string filename, int type) {
    Identity *person = NULL;
    ifstream ifs;
    ifs.open(filename, ios::in);
    if (!ifs.is_open()) {
        cout << "the file isn't exist!" << endl;
        ifs.close();
        return;
    }
    int id = 0;
    string name;
    string pwd;

    // verify the login
    if (type == 1) {
        cout << "Please enter your student ID: ";
        cin >> id;
    } else if (type == 2) {
        cout << "Please enter your teacher ID: ";
        cin >> id;
    }
    cout << "Please enter your name: ";
    cin >> name;

    cout << "Please enter your password: ";
    cin >> pwd;

    if (type == 1) {
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
            if (id == fId && name == fName && pwd == fPwd) {
                cout << "Student verify successfully!" << endl;
                person = new Student(id, name, pwd);
                studentMenu(person);
                return;
            }
        }
    } else if (type == 2) {
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
            if (id == fId && name == fName && pwd == fPwd) {
                cout << "Teacher verify successfully!" << endl;
                person = new Teacher(id, name, pwd);
                teacherMenu(person);
                return;
            }
        }
    } else if (type == 3) {
        string fName;
        string fPwd;
        while (ifs >> fName && ifs >> fPwd) {
            if (name == fName && pwd == fPwd) {
                cout << "Teacher verify successfully!" << endl;
                person = new Manager(name, pwd);
                managerMenu(person);
                return;
            }
        }
    }
    cout << "Login failed!" << endl;
    return;
}

int main(int argc, char *argv[]) {
    int select = 0;
    cout << "Please enter your identity" << endl;
    cout << "\t\t------------------------\n";
    cout << "\t\t|                      |\n";
    cout << "\t\t|      1.Student       |\n";
    cout << "\t\t|                      |\n";
    cout << "\t\t|      2.Teacher       |\n";
    cout << "\t\t|                      |\n";
    cout << "\t\t|      3.Manager       |\n";
    cout << "\t\t|                      |\n";
    cout << "\t\t|      0.Exit          |\n";
    cout << "\t\t|                      |\n";
    cout << "\t\t------------------------\n";
    cout << "Please enter your choice: ";
    cin >> select;
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
        cout << "See you again!" << endl;
        return 0;
        break;
    default:
        cout << "The choice is wrong!" << endl;
        break;
    }
    return 0;
}
