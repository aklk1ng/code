#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Greater1
{
    public:
        bool operator() (int val) {
            return val > 5;
        }
    };
class Person
{
    public:
        Person(string name, int age) {
            this->m_name = name;
            this->m_age = age;
        }
        string m_name;
        int m_age;
    };
class Greater2
{
    public:
        bool operator() (Person &p) {
            return p.m_age > 20;
        }
    };
void test()
{
    vector<int>v; 
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    vector<int>::iterator it = find_if(v.begin(), v.end(), Greater1());
    if (it == v.end()) {
        cout << "find failed" << endl;
    } else cout << *it << endl;

    vector<Person>v2;
    Person p1("a", 1);
    Person p2("b", 4);
    Person p3("ed", 2);
    Person p4("sdf", 70);
    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    v2.push_back(p4);
    vector<Person>::iterator pos = find_if(v2.begin(), v2.end(), Greater2());
    if (pos == v2.end()) {
        cout << "find failed" << endl;
    } else cout << pos->m_name << " " << pos->m_age << endl;

}
int main (int argc, char *argv[])
{
    test();     
    return 0;
}
