
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// find algorithms
class Person
{
    public:
        Person(string name, int age) {
            this->m_name = name;
            this->m_age = age;
        }
        // overload the == operator to let the find function source code
        // know how to compare the type of data
        bool operator== (const Person &p) {
            if (this->m_name == p.m_name && this->m_age == p.m_age) {
                return true;
            } else return false;
        }
        string m_name;
        int m_age;
    };
void test2()
{
    vector<int>v; 
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    vector<int>::iterator pos = find(v.begin(), v.end(), 5);
    if (pos == v.end()) {
        cout << "find failed" << endl;
    } else cout << *pos << endl; 

    vector<Person>v1;
    Person p1("aaa", 10);
    Person p2("vvvv", 12);
    Person p3("bbb", 8);
    Person p4("yy", 16);
    v1.push_back(p1);
    v1.push_back(p2);
    v1.push_back(p3);
    v1.push_back(p4);
    vector<Person>::iterator it = find(v1.begin(), v1.end(), p2);
    if (it == v1.end()) {
        cout << "find failed" << endl;
    } else cout << it->m_name << " " << it->m_age << endl; 
}
int main (int argc, char *argv[])
{
    test2();
    return 0;
}
