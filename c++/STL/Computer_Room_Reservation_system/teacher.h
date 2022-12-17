#pragma once
#include "Computer_Room_Reservation.h"
#include "Identity.h"
class Teacher :public Identity
{
    public:
        Teacher();
        Teacher(int empId, string name, string pwd);
        virtual void operMenu();
        void showAllOrder();
        void validOrder();
            
        int m_EmpId;
    };
