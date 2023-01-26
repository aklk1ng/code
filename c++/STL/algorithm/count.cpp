#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Person {
  public:
    Person(string name, int age) {
        this->m_name = name;
        this->m_age = age;
    }
    bool operator==(const Person &p) {
        if (this->m_age == p.m_age) {
            return true;
        } else
            return false;
    }
    string m_name;
    int m_age;
};
void test() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    int num = count(v.begin(), v.end(), 5);
    cout << num << endl;

    vector<Person> v2;
    Person p1("a", 0);
    Person p2("b", 2);
    Person p3("c", 2);
    Person p4("d", 0);
    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    v2.push_back(p4);
    int pos = count(v2.begin(), v2.end(), p1);
    cout << pos << endl;
}
int main(int argc, char *argv[]) {
    test();
    return 0;
}
