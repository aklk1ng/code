#include <iostream>
#include <set>
#include <utility>
using namespace std;

void Print(set<int> &s) {
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
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
class MyCompare {
public:
    bool operator()(int v1, int v2) { return v1 > v2; }
};
void test() {
    set<int> s;
    s.insert(3);
    s.insert(0);
    s.insert(1);
    s.insert(2);
    pair<set<int>::iterator, bool> ret = s.insert(2);
    if (ret.second) {
        cout << "insert successful" << endl;
    } else
        cout << "insert failed" << endl;
    s.insert(4);
    if (!s.empty()) {
        Print(s);
        cout << s.size() << endl;
        s.erase(s.begin());
        Print(s);
        s.erase(2);
    }

    set<int> s1;
    s1.swap(s);
    Print(s1);
    cout << s1.size() << endl;
}

// set container find and count
void test1() {
    set<int> s;
    s.insert(3);
    s.insert(0);
    s.insert(1);
    s.insert(2);
    // use the pair
    pair<set<int>::iterator, bool> ret = s.insert(2);
    if (ret.second) {
        cout << "insert successful" << endl;
    } else
        cout << "insert failed" << endl;
    s.insert(4);
    set<int>::iterator pos = s.find(2);
    if (pos != s.end()) {
        s.erase(pos);
    }
    cout << s.count(4) << endl;
    Print(s);

    multiset<int> ms;
    ms.insert(10);
    ms.insert(10);
    for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
        cout << *it << endl;
    }
}

// create the pair
void test2() {
    pair<string, int> p("A", 20);
    cout << p.first << " " << p.second << endl;

    pair<string, int> p2 = make_pair("ABC", 30);
    cout << p2.first << " " << p2.second << endl;
}

// set container sort
void test3() {
    set<int> s;
    s.insert(3);
    s.insert(0);
    s.insert(1);
    s.insert(2);
    s.insert(1);
    s.insert(0);
    Print(s);

    set<int, MyCompare> s2;
    s2.insert(3);
    s2.insert(0);
    s2.insert(1);
    s2.insert(2);
    s2.insert(1);
    s2.insert(0);
    for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

class comparePerson {
  public:
    bool operator()(const Person &p1, const Person &p2) {
        return p1.m_age > p2.m_age;
    }
};
void test4() {
    set<Person, comparePerson> s;
    Person p1("a", 21);
    Person p2("b", 23);
    Person p3("asdf", 16);
    Person p4("sdfds", 20);
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);
    for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end();
         it++) {
        cout << it->m_name << " " << it->m_age << endl;
    }
}
int main(int argc, char *argv[]) {

    /* test(); */
    /* test1(); */
    /* test2(); */
    /* test3(); */
    test4();
    return 0;
}
