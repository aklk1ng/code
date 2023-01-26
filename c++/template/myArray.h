#pragma once
#include<iostream>
using namespace std;
template<class T>
class MyArray {
public:
    //有参构造
    MyArray(int capacity) {
        cout << "有参构造"<<endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }
    MyArray(const MyArray& arr) {
        cout << "拷贝构造"<<endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;

        this->pAddress = new T[arr.m_Capacity];
        for (int i = 0; i < this->m_Size; i++) {
            this->pAddress[i] = arr.pAddress[i];
        }
    }
    //operator
    MyArray& operator=(const MyArray& arr) {
        cout << "operator构造"<<endl;
        if (this->pAddress != NULL) {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }
        //深拷贝
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[this->m_Capacity];
        for (int i = 0; i < this->m_Size; i++) {
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }
    ~MyArray() {
        cout << "析构"<<endl;
        if (this->pAddress != NULL) {
            delete [] this->pAddress;
            this->pAddress = NULL;
        }
    }
private:
    T m_Capacity;
    T* pAddress;
    T m_Size;
};
