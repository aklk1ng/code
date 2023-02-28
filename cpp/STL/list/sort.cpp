#include <iostream>
#include <list>
#include <string>
using namespace std;

class Person {
public:
  Person(string name, int age, int height) {
    this->m_name = name;
    this->m_age = age;
    this->m_height = height;
  }
  string m_name;
  int m_age;
  int m_height;
};
bool ComparePerson(Person &p1, Person &p2) {
  if (p1.m_age == p2.m_age) {
    // descending
    return p1.m_height > p2.m_height;
  }
  // ascending
  return p1.m_age < p2.m_age;
}
void test() {
  list<Person> l;
  Person p1("A", 20, 160);
  Person p2("BC", 19, 177);
  Person p3("C", 19, 155);
  Person p4("DF", 30, 190);
  Person p5("LOL", 8, 177);

  l.push_back(p1);
  l.push_back(p2);
  l.push_back(p3);
  l.push_back(p4);
  l.push_back(p5);

  auto it = l.begin();
  for (; it != l.end(); it++) {
    cout << it->m_name << "\t" << it->m_age << "\t" << it->m_height << endl;
  }

  l.sort(ComparePerson);
  cout << "--------------" << endl;
  it = l.begin();
  for (; it != l.end(); it++) {
    cout << it->m_name << "\t" << it->m_age << "\t" << it->m_height << endl;
  }
}
int main(int argc, char *argv[]) {
  test();
  return 0;
}
