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
    Manager(string name, string pwd);
    virtual void operMenu();

    void addPerson();
    void initVector();
    void initComputer();
    bool checkRepeat(int id, int type);
    void showPerson();
    void showComputer();
    void cleanFile();

    vector<Student> vStu;
    vector<Teacher> vTea;
    vector<ComputerRoom> vCom;
};
