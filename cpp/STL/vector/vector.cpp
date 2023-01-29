#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void myPrint(int val) {
    cout << val << endl;
}

void PrintVector(vector<int> &v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test1() {
    // create a vector container
    vector<int> v;

    // push data to the container
    v.push_back(10);
    v.push_back(20);
    v.push_back(1);
    v.push_back(40);
    v.push_back(8);

    /*     // use the iterator to get the data in the container */
    /*     vector<int>::iterator itBegin = v.begin(); // the begin iterator
     * points to the first element int the container */
    /*     vector<int>::iterator itEnd = v.end(); // the end iterator points to
     * the next position of the last element in the container */

    /*     // the first traverse */
    /*     while (itBegin != itEnd) { */
    /*         cout<<*itBegin<<endl; */
    /*         itBegin++; */
    /*     } */

    /* // the second traverse */
    /* for (vector<int>::iterator it = v.begin(); it != v.end(); it++) { */
    /*     cout << *it << endl; */
    /* } */

    // the third traverse --- the traverse algorithm(for_each)
    for_each(v.begin(), v.end(), myPrint); // use the callback
}

class Person {
public:
    Person(string name, int age) {
        this->m_name = name;
        this->m_age = age;
    }
    string m_name;
    int m_age;
};

void test2() {
    vector<Person> v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
        /* cout << (*it).m_name << '\t' << (*it).m_age << endl; */
        cout << it->m_name << '\t' << it->m_age << endl;
    }
}

void test3() {
    vector<Person *> v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++) {
        /* cout << (*(*it)).m_name << '\t' << (*(*it)).m_age << endl; */
        cout << (*it)->m_name << '\t' << (*it)->m_age << endl;
    }
}

void test4() {
    vector<vector<int>> v;

    // the small container
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;
    for (int i = 0; i < 4; i++) {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
    }

    // push the small container to the big container
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end();
             vit++) {
            cout << *vit << " ";
        }
        cout << endl;
    }
}

void test5() {
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
        cout << v1[i];
    }
    cout << endl;

    // in this way the end isn't not include
    vector<int> v2(v1.begin(), v1.end());
    for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
        cout << *it << endl;
    }

    vector<int> v3(10, 100);
    for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++) {
        cout << *it << endl;
    }

    vector<int> v4(v3);
    for (vector<int>::iterator it = v4.begin(); it != v3.end(); it++) {
        cout << *it << endl;
    }
}

// vector assignment operator
void test6() {
    vector<int> v1;
    for (int i = 0; i < 5; i++) {
        v1.push_back(i);
    }
    vector<int> v2;
    v2 = v1;
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
        cout << *it << endl;
    }
    cout << endl;

    vector<int> v3;
    v3.assign(v1.begin(), v1.end());
    for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
        cout << *it << endl;
    }
    cout << endl;

    vector<int> v4;
    v4.assign(3, 6);
    for (vector<int>::iterator it = v4.begin(); it != v4.end(); it++) {
        cout << *it << endl;
    }
    cout << endl;
}

// vector capacity and size -- the capacity is dymatic and auto-incremented
void test7() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    PrintVector(v);

    if (!v.empty()) {
        cout << "true" << endl;
        cout << v.size() << endl;
        cout << v.capacity() << endl;
    } else
        cout << "false" << endl;

    v.resize(
        20); // the compile will use the defaults value to filling the new space
    PrintVector(v);

    v.resize(30, 6);
    PrintVector(v);
    cout << v.capacity() << endl;
}

// vector instert and erase
void test8() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    PrintVector(v);
    v.pop_back();
    PrintVector(v);
    v.insert(v.begin(), -1);
    v.insert(v.end(), 9);
    PrintVector(v);
    v.insert(v.begin(), 2, -1);
    PrintVector(v);
    v.erase(v.begin());
    PrintVector(v);
    v.clear();
    /* v.erase(v.begin(), v.end()); */
    PrintVector(v);
}

// vector data access
void test9() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << " ";
    }
    cout << endl;
    cout << v.front() << " " << v.back() << endl;
}

// vector swap and reserve
void test10() {
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    /* PrintVector(v1); */
    vector<int> v2;
    for (int i = 10; i > 0; i--) {
        v2.push_back(i);
    }
    PrintVector(v1);
    PrintVector(v2);

    v2.swap(v1);
    PrintVector(v1);
    PrintVector(v2);

    vector<int> v3;
    v3.reserve(100000);
    int num = 0;
    int *p = NULL;
    for (int i = 0; i < 100000; i++) {
        v3.push_back(i);
        if (p != &v3[0]) {
            p = &v3[0];
            num++;
        }
    }
    cout << num << endl;
    cout << v3.capacity() << endl;
    cout << v3.size() << endl;

    v3.resize(10);
    // shrink space
    vector<int>(v3).swap(v3);

    cout << v3.capacity() << endl;
    cout << v3.size() << endl;
}
int main(int argc, char *argv[]) {
    /* test1(); */
    /* test2(); */
    /* test3(); */
    /* test4(); */
    /* test5(); */
    /* test6(); */
    /* test7(); */
    /* test8(); */
    /* test9(); */
    test10();
    return 0;
}
