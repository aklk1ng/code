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
/* class Child final: public Base { */ /* class Child final: public Base { */
/* class Child final: public Base { */ /* class Child final: public Base { */
/* class Child final: public Base { */ /* class Child final: public Base { */
/* class Child final: public Base { */ /* class Child final: public Base { */
                                       /* class Child final: public Base { */
/* class Child final: public Base { */ /*     // couldn't override the virtual
                                          function if use the final keyword */
/*     // override make sure you must rewrite the virtual function not write a
 * new function */
/*     void test() override final { */
/*         cout << "Child class" << endl; */
/*     } */

/* private: */

/* }; */
/* class Child final: public Base { */ /* class Child final: public Base { */
/* class Child final: public Base { */ /* class Child final: public Base { */
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

// default template paramters
/* #include <iostream> */
/* using namespace std; */

/* template <typename T = long, typename U = int> */
/* void test(T t = 'A', U u = 'B') { */
/*     cout << t << u << endl; */
/* } */

/* int main(int argc, char *argv[]) { */
/*     test(); */
/*     test<int>('a', 'b'); */
/*     return 0; */
/* } */

// using
/* #include <iostream> */
/* using namespace std; */

/* int test(int a, int b) { */
/*     cout << a << " " << b << endl; */
/*     return 0; */
/* } */
/* typedef int(*func) (int, int); */
/* using func1 = int(*) (int, int); */

/* int main(int argc, char *argv[]) { */
/*     func f = test; */
/*     func1 f1 = test; */
/*     f(10, 20); */
/*     f1(1, 2); */
/*     (*f)(4, 4); */
/*     return 0; */
/* } */

// delegating constructor
/* #include <iostream> */
/* using namespace std; */

/* class test { */
/*     public: */
/*         test(); */
/*         test(int max) { */
/*             this->m_max = max > 0 ? max : 100; */
/*         } */
/*         test(int max, int min) :test(max) { */
/*             this->m_min = min > 0 && min < max ? min : 1; */
/*             cout << this->m_min; */
/*         } */
/*         test(int max, int min, int mid):test(max, min) { */
/*             this->m_middle = mid < max && mid > min ? mid : 50; */
/*             cout << this->m_middle; */
/*         } */
/*     private: */
/*         int m_min; */
/*         int m_max; */
/*         int m_middle; */
/* }; */
/* int main(int argc, char *argv[]) { */
/*     test t(10, 5, 7); */
/*     return 0; */
/* } */

// inherited constructor
/* #include <iostream> */
/* using namespace std; */

/* class Base { */
/* public: */
/*     Base(int i) :m_i(i) {} */
/*     Base(int i, double j) :m_i(i), m_j(j) {} */
/*     Base(int i, double j, string k) :m_i(i), m_j(j), m_k(k) {} */
/*     void func(int i) { */
/*         cout << i << endl; */
/*     } */
/*     void func(int i, string k) { */
/*         cout << i << " " << k << endl; */
/*     } */
/*     int m_i; */
/*     double m_j; */
/*     string m_k; */
/* }; */

/* class Child : public Base { */
/* public: */
/*     using Base::Base; */
/*     using Base::func; */
/*     void func() { */
/*         cout << "call func()" << endl; */
/*     } */
/*     /1* Child(int i) :Base(i) {} *1/ */
/*     /1* Child(int i, double j) :Base(i, j) {} *1/ */
/*     /1* Child(int i, double j, string k) : Base(i, j, k) {} *1/ */

/* private: */

/* }; */
/* int main(int argc, char *argv[]) { */
/*     Child c(520, 13.14, "i love you"); */
/*     cout << c.m_i << c.m_j << c.m_k << endl; */
/*     c.func(); */
/*     c.func(1); */
/*     c.func(4, "haha"); */
/*     return 0; */
/* } */

// initiallization list
/* #include <initializer_list> */
/* #include <iostream> */
/* using namespace std; */

/* class Person { */
/*     public: */
/*         Person(int i , int j) : m_i(i), m_j(j) {} */
/*     private: */
/*         int m_i; */
/*         int m_j; */
/* }; */

/* void func(initializer_list<int> ls) { */
/*     auto it = ls.begin(); */
/*     for (; it != ls.end(); it++) { */
/*         cout << (*it) << "\t"; */
/*     } */
/*     cout << endl; */
/* } */
/* int main(int argc, char *argv[]) { */
/*     Person p = {1, 2}; */
/*     func({1, 2, 3, 4}); */
/*     return 0; */
/* } */

// for
/* #include <iostream> */
/* #include <vector> */
/* using namespace std; */

/* int main(int argc, char *argv[]) { */
/*     vector<int> v {1, 2, 3, 4, 5}; */
/*     for(const auto &item : v) { */
/*         cout << item << "\t"; */
/*     } */
/*     cout << endl; */
/*     return 0; */
/* } */

// callable object
/* #include <iostream> */
/* #include <string> */
/* #include <functional> */
/* using namespace std; */

/* void output(int a, int b) { */
/*     cout << a << " " << b << " " << a + b << endl; */
/* } */

/* void print(int num, string name) { */
/*     cout << num << " " << name << endl; */
/* } */
/* using funcptr = void(*)(int, string); */

/* class test { */
/* public: */
/*     // overload */
/*     void operator()(string msg) { */
/*         cout << msg << endl; */
/*     } */
/*     // convert class object to function pointer */
/*     operator funcptr() { */
/*         // the return value must be a static function type */
/*         return world; */
/*     } */
/*     void output(int a, int b) { */
/*         cout << a << " " << b << " " << a + b << endl; */
/*     } */
/*     void hello(int a, string s) { */
/*         cout << a << s << endl; */
/*     } */
/*     static void world(int a, string s) { */
/*         cout << a << s << endl; */
/*     } */
/*     int m_id = 520; */
/*     string m_name = "alkk1ng"; */

/* private: */

/* }; */

/* class A { */
/* public: */
/*     A(const function<void(int, string)>& f) : callback(f) { */

/*     } */
/*     void notify(int id, string name) { */
/*         callback(id, name); */
/*     } */
/*     int m_number = 100; */

/* private: */
/*     function<void(int, string)> callback; */
/* }; */

/* void test1() { */
/*     test t; */
/*     t("hello"); */

/*     test tt; */
/*     tt(1, "king"); */

/*     // class function pointer -- only used for static function */
/*     funcptr f = test::world; */
/*     f(1, "funcptr"); */
/*     using fptr = void(test::*)(int, string); */
/*     fptr f1 = &test::hello; */

/*     // class member variable pointer */
/*     using ptr1 = int test::*; */
/*     ptr1 pt = &test::m_id; */

/*     test ttt; */
/*     (ttt.*f1)(1, "Aklk1ng"); */
/*     ttt.*pt = 10; */
/*     cout << ttt.*pt << endl; */
/* } */

/* void test2() { */
/*     // ordinary function */
/*     function<void(int, string)> f1 = print; */
/*     f1(1, "ace"); */
/*     // static function */
/*     function<void(int, string)> f2 = test::world; */
/*     f2(2, "alkk1ng"); */
/*     // functor */
/*     test ta; */
/*     function<void(string)> f3 = ta; */
/*     f3("Aklk1ng"); */
/*     // class object converted to function pointer */
/*     test tb; */
/*     function<void(int, string)> f4 = tb; */
/*     f4(3, "callback"); */
/* } */

/* void test3() { */
/*     A aa(print); */
/*     aa.notify(1, "ace"); */
/*     A ab(test::world); */
/*     ab.notify(2, "aklk1ng"); */
/*     test ta; */
/*     A ac(ta); */
/*     ac.notify(3, "Aklk1ng"); */

/* } */

/* void testFunc(int x, int y, const function<void(int, int)>& f) { */
/*     if (x % 2 == 0) { */
/*         f(x, y); */
/*     } */
/* } */

/* // binder */
/* void test4() { */
/*     bind(print, placeholders::_1, placeholders::_2)(1, "string"); */

/*     for (int i = 0; i < 10; i++) { */
/*         auto f = bind(output, i, i + 1); */
/*         testFunc(i, i, f); // use i,i + 1 not i,i */
/*         cout << "---------------" << endl; */
/*         auto f1 = bind(output, placeholders::_1, placeholders::_2); */
/*         testFunc(i, i, f1); */
/*     } */

/*     // class member function */
/*     test t; */
/*     auto f = bind(&test::output, &t, 1, placeholders::_1); */
/*     function<void(int, int)> ff = bind(&test::output, &t, 1,
 * placeholders::_1); */
/*     f(1314); */

/*     // class member variable */
/*     auto f1 = bind(&test::m_id, &t); */
/*     function<int&(void)> f11 = bind(&test::m_id, &t); */
/*     cout << f1() << endl; */
/* } */

/* int main(int argc, char *argv[]) { */
/*     /1* test2(); *1/ */
/*     /1* test3(); *1/ */
/*     test4(); */
/*     return 0; */
/* } */

// lambda
/* #include <iostream> */
/* #include <functional> */
/* using namespace std; */

/* using funptr = void(*)(int); */

/* class test { */
/* public: */
/*     // used to function pointer */
/*     funptr p1 = [](int x) { */
/*         cout << x << endl; */
/*     }; */

/*     function<void(int)> ff = [=](int x) { */
/*         cout << x << endl; */
/*     }; */

/*     function<void(int)> fff = bind([=](int x) { */
/*         cout << x << endl; */
/*     }, placeholders::_1); */

/*     void output(int x, int y) { */
/*         auto x1 = [=]() {return m_number;}(); */
/*         auto x2 = [=]() {return x + y;}(); */
/*         this->print(x1); */
/*         this->print(x2); */
/*     } */
/*     int m_number = 100; */
/*     static void print(int a) { */
/*         cout << a << endl; */
/*     } */

/* private: */

/* }; */

/* int main(int argc, char *argv[]) { */
/*     test t; */
/*     t.output(1, 2); */
/*     t.p1(11); */
/*     t.ff(1); */
/*     t.fff(111); */
/*     return 0; */
/* } */

// read value quote
/* #include <cstdio> */
/* #include <iostream> */
/* #include <utility> */
/* using namespace std; */

/* class Test { */
/* public: */
/*     Test() : m_num(new int(100)) { */
/*         cout << "create construct" << endl; */
/*         cout << m_num << endl; */
/*     } */
/*     Test(const Test &a) : m_num(new int(*a.m_num)) { */
/*         cout << "copy construct" << endl; */
/*     } */
/*     Test(Test &&a) :m_num(a.m_num) { */
/*         a.m_num = nullptr; */
/*         cout << "move construct" << endl; */
/*     } */
/*     ~Test() { */
/*         cout << "destruct Test class" << endl; */
/*         delete m_num; */
/*     } */
/*     int *m_num; */

/* private: */

/* }; */

/* Test getObj() { */
/*     Test t; */
/*     return t; */
/* } */

/* void test() { */
/*     int num = 1; */
/*     int &&a = 8; */
/*     const int &b = num; */
/*     const int &&c = 10; */
/* } */

/* void test1() { */
/*     Test t = getObj(); */
/*     cout << endl; */
/*     Test &&t1 = getObj(); */
/*     cout << t1.m_num << endl; */
/* } */
/* int main(int argc, char *argv[]) { */
/*     test1(); */
/*     return 0; */
/* } */

// move
/* #include <iostream> */
/* #include <utility> */
/* #include <list> */
/* using namespace std; */

/* class Test { */
/* public: */
/*     Test() : m_num(new int(100)) { */
/*         cout << "create construct" << endl; */
/*         cout << m_num << endl; */
/*     } */
/*     Test(const Test &a) : m_num(new int(*a.m_num)) { */
/*         cout << "copy construct" << endl; */
/*     } */
/*     Test(Test &&a) :m_num(a.m_num) { */
/*         a.m_num = nullptr; */
/*         cout << "move construct" << endl; */
/*     } */
/*     ~Test() { */
/*         cout << "destruct Test class" << endl; */
/*         delete m_num; */
/*     } */
/*     int *m_num; */

/* private: */

/* }; */

/* Test getObj() { */
/*     Test t; */
/*     return t; */
/* } */
/* void test() { */
/*     Test t = getObj(); */
/*     Test &&t1 = getObj(); */
/*     Test &&t2 = move(t1); */
/*     Test &&t3 = move(t); */

/*     list<string> ls1 { */
/*         "heelo", "world", "hihao" */
/*     }; */
/*     list<string> ls2 = move(ls1); */
/* } */

/* int main(int argc, char *argv[]) { */
/*     test(); */
/*     return 0; */
/* } */

// forward
/* #include <iostream> */
/* #include <utility> */
/* using namespace std; */

/* template <typename T> */
/* void printvalue(T &t) { */
/*     cout << "l-value" << t << endl; */
/* } */
/* template <typename T> */
/* void printvalue(T &&t) { */
/*     cout << "r-value" << t << endl; */
/* } */
/* template <typename T> */
/* void testForward(T &&v) { */
/*     printvalue(v); */
/*     printvalue(move(v)); */
/*     printvalue(forward<T>(v)); */
/*     cout << endl; */
/* } */

/* void test() { */
/*     testForward(520); */
/*     int num = 1314; */
/*     testForward(num); */
/*     testForward(forward<int>(num)); */
/*     testForward(forward<int&>(num)); */
/*     testForward(forward<int&&>(num)); */
/* } */

/* int main(int argc, char *argv[]) { */
/*     test(); */
/*     return 0; */
/* } */









// shared_ptr
/* #include <ctime> */
/* #include <iostream> */
/* #include <memory> */
/* #include <string> */
/* #include <utility> */
/* using namespace std; */

/* class Test { */
/* public: */
/*     Test() { cout << "construct Test.." << endl; } */
/*     Test(int x) : m_num(x) { cout << "construct Test, x = " << x << endl; } */
/*     Test(string str) { cout << "construct Test, str = " << str << endl; } */
/*     ~Test() { cout << "destruct Test..." << endl; } */
/*     void setvalue(int v) { m_num = v; } */
/*     void print() { cout << m_num << endl; } */

/* private: */
/*     int m_num; */
/* }; */

/* void deleteIntPtr(int *p) { */
/*     delete p; */
/*     cout << "the memory free successfully" << endl; */
/* } */
/* void test() { */
/*     shared_ptr<int> ptr1(new int(520), [](int *ptr){ */
/*             delete ptr; */
/*             cout << "----------------" << endl; */
/*             }); */
/*     cout << ptr1.use_count() << endl; */
/*     shared_ptr<int> ptr2(ptr1); */
/*     cout << ptr2.use_count() << endl; */
/*     shared_ptr<int> ptr3 = ptr1; */
/*     cout << ptr3.use_count() << endl; */
/*     shared_ptr<int> ptr4 = move(ptr1); */
/*     cout << ptr1.use_count() << endl; */
/*     cout << ptr4.use_count() << endl; */
/*     shared_ptr<int> ptr5 = move(ptr2); */
/*     cout << ptr5.use_count() << endl; */
/*     cout << ptr5.get() << endl; */
/*     ptr4.reset(); */
/*     cout << ptr4.use_count() << endl; */
/*     ptr5.reset(new int(99)); */
/*     cout << ptr5.use_count() << endl; */
/* } */
/* void test1() { */
/*     shared_ptr<Test> ptr1 = make_shared<Test>(1314); */
/*     shared_ptr<Test> ptr2(new Test(100), default_delete<Test>()); */
/* } */
/* int main(int argc, char *argv[]) { */
/*     test(); */
/*     test1(); */
/*     return 0; */
/* } */






// unique_ptr
/* #include <iostream> */
/* #include <memory> */
/* #include <utility> */
/* using namespace std; */

/* unique_ptr<int> func() { */
/*     return unique_ptr<int>(new int(520)); */
/* } */
/* using func_ptr = void(*)(int*); */
/* void test() { */
/*     unique_ptr<int, func_ptr> ptr1(new int(10), [](int *p) { */
/*             delete p; */
/*             cout << "---------------" << endl; */
/*             }); */
/*     unique_ptr<int, func_ptr> ptr2 = move(ptr1); */
/*     ptr1.reset(); */
/*     ptr2.reset(new int(100)); */

/*     // unique_ptr can free the array memory aucomatically */
/*     unique_ptr<int[]> ptr3(new int[5]); */
/* } */
/* int main(int argc, char *argv[]) { */
/*     test(); */
/*     return 0; */
/* } */









//  weak_ptr
#include <iostream>
#include <memory>
using namespace std;

void test() {
    shared_ptr<int> sp(new int);
    weak_ptr<int> wp1;
    weak_ptr<int> wp2(wp1);
    weak_ptr<int> wp3(sp);
    cout << wp3.use_count() << endl;
    cout << wp3.lock() << endl;
    sp.reset();
    weak_ptr<int> wp4;
    wp4 = sp;
    weak_ptr<int> wp5;
    wp5 = wp3;
    cout << wp5.use_count() << endl;
    wp5.reset();
    cout << wp5.expired() << endl;
}
int main(int argc, char *argv[]) {
    test();
    return 0;
}
