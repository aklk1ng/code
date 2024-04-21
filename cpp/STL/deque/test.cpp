#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

class Person {
public:
  Person(string name, int score) {
    this->m_name = name;
    this->m_score = score;
  }

  string m_name;
  int m_score;
};

void createPerson(vector<Person> &v) {
  string nameSeed = "ABCDE";
  for (int i = 0; i < 5; i++) {
    string name = "Person";
    name += nameSeed[i];
    int score = 0;
    Person p(name, score);
    v.push_back(p);
  }
}

void setScore(vector<Person> &v) {
  for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
    deque<int> d;
    for (int i = 0; i < 10; i++) {
      int score = rand() % 41 + 60;
      d.push_back(score);
    }
    /* cout << it->m_name << " " << endl; */
    /* for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
     */
    /*     cout << *dit << " "; */
    /* } */
    /* cout << endl; */
    sort(d.begin(), d.end());
    d.pop_back();
    d.pop_front();

    int sum = 0;
    for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
      sum += *dit;
    }
    int avg = sum / d.size();

    it->m_score = avg;
  }
}

void showScore(vector<Person> &p) {
  for (vector<Person>::iterator it = p.begin(); it != p.end(); it++) {
    cout << it->m_name << " " << it->m_score << endl;
  }
}

void test1() {
  srand((unsigned int)time(NULL));
  vector<Person> v;
  createPerson(v);
  /* for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) { */
  /*     cout << (*it).m_name << " " << (*it).m_score << endl; */
  /* } */
  setScore(v);
  showScore(v);
}

int main(int argc, char *argv[]) {
  test1();
  return 0;
}
