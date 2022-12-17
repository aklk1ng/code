#pragma once
#include "Computer_Room_Reservation.h"
#include <map>
#include <fstream>
#include <string>
class OrderFile
{
    public:
        OrderFile();
        void updateOrder();
        map<int, map<string, string>>m_orderData;
        int m_Size;
    };
