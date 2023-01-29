#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Greater {
public:
    bool operator()(int val) { return val > 5; }
};
class Person {
public:
    Person(string name, int age) {
        this->m_name = name;
        this->m_age = age;
    }
    string m_name;
    int m_age;
};
class Compare_Age {
public:
    bool operator()(const Person &p) { return p.m_age > 1; }
};
void test() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    int num = count_if(v.begin(), v.end(), Greater());
    cout << num << endl;
    vector<Person> v2;
    Person p1("a", 0);
    Person p2("b", 3);
    Person p3("c", 3);
    Person p4("d", -1);
    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    v2.push_back(p4);
    int count = count_if(v2.begin(), v2.end(), Compare_Age());
    cout << count << endl;
}
int main(int argc, char *argv[]) {
    test();
    return 0;
}
