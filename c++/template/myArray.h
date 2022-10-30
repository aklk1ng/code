#pragma once
#include<iostream>
using namespace std;
template<class T>
class MyArray
{
    public:
        MyArray(int capacity) {
            this->m_Capacity = capacity;
            this->m_Size = 0;
            this->pAddress = new T[this->m_Capacity];
        }
        ~MyArray() {
            if (this->pAddress != NULL) {
                delete [] this->pAddress;
                this->pAddress = NULL;
            }
        }
    private:
        int m_Capacity;
};
