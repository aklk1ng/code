// nullptr
/* #include <iostream> */
/* using namespace std; */
/* void func(char* p) */
/* { */
/*     cout<<"void functin char *p"<<endl; */
/* } */
/* void func(int p) */
/* { */
/*     cout<<"void function int p"<<endl; */
/* } */
/* int main(int argc, char *argv[]) */
/* { */
/*     int* ptr1 = nullptr; */
/*     char* ptr2 = nullptr; */
/*     double* ptr3 = nullptr; */
/*     void* ptr4 = nullptr; */
/*     int* ptr5 = (int*)ptr4; */
/*     func(10); */
/*     func(nullptr); */
/*     return 0; */
/* } */

/* #include <iostream> */
/* using namespace std; */
/* void test(int arr[], int len) { */
/*     for (int i = 0; i < len - 1; i++) { */
/*         for (int j = 0; j < len - 1 - i; j++) { */
/*             if (arr[j] > arr[j + 1]) { */
/*                 int tmp = arr[j]; */
/*                 arr[j] = arr[j + 1]; */
/*                 arr[j + 1] = tmp; */
/*             } */
/*         } */
/*     } */
/* } */
/* int main(int argc, char *argv[]) { */
/*     int arr[] = {1, 4, 0, 4, 6, 1, 5}; */
/*     int len = sizeof(arr) / sizeof(arr[0]); */
/*     cout << len << endl; */
/*     for (int i = 0; i < len; i++) { */
/*         cout << arr[i] << " "; */
/*     } */
/*     test(arr, len); */
/*     cout << "\n"; */
/*     for (int i = 0; i < len; i++) { */
/*         cout << arr[i] << " "; */
/*     } */
/*     return 0; */
/* } */

// decltype--声明类型,自动推导
/* #include <cstdio> */
/* #include <iostream> */
/* #include <list> */
/* using namespace std; */

/* template<typename T> */
/* class Container { */
/*     public: */
/*         void print(T &t) { */
/*             for (m_it = t.begin(); m_it != t.end(); m_it++) { */
/*                 cout << *m_it << endl; */
/*             } */
/*         } */
/*     private: */
/*         decltype(T().begin()) m_it; */
/* }; */

/* template<typename T, typename U> */
/* auto add(T t, U u) -> decltype(t + u){ */
/*     return t + u; */
/* } */

/* int main(int argc, char *argv[]) { */
/*     int x = 520; */
/*     double y = 13.14; */
/*     auto ret = add<int, double>(x, y); */
/*     auto ret1 = add(x, y); */
/*     list<int> ls{1, 2, 3, 4 ,5}; */
/*     Container<list<int>> c; */
/*     c.print(ls); */
/*     cout << ret << endl; */
/*     cout << ret1 << endl; */
/*     return 0; */
/* } */


// final | override
/* #include <iostream> */
/* using namespace std; */

/* class Base { */
/* public: */
/*     virtual void test() { */
/*         cout << "Base class" << endl; */
/*     } */
/* private: */

/* }; */

/* class Child final: public Base { */
/* public: */
/* class Child final: public Base { *//* class Child final: public Base { *//* class Child final: public Base { *//* class Child final: public Base { *//* class Child final: public Base { *//* class Child final: public Base { *//* class Child final: public Base { *//* class Child final: public Base { *//* class Child final: public Base { *//* class Child final: public Base { *//*     // couldn't override the virtual function if use the final keyword */
/*     // override make sure you must rewrite the virtual function not write a new function */
/*     void test() override final { */
/*         cout << "Child class" << endl; */
/*     } */

/* private: */

/* }; */
/* class Child final: public Base { *//* class Child final: public Base { *//* class Child final: public Base { *//* class Child final: public Base { */
/* /1* class GrandChild : public Child { *1/ */
/* /1* public: *1/ */
/* /1*     void test() { *1/ */
/* /1*         cout << "GrandChild class" << endl; *1/ */
/* /1*     } *1/ */

/* /1* private: *1/ */

/* /1* }; *1/ */

/* int main(int argc, char *argv[]) { */

/*     return 0; */
/* } */


// template closing angle bracket
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

    return 0;
}
