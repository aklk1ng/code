#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;

void Print(map<int, int> &m) {
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << (*it).first << " " << (*it).second << endl;
    }
    cout << endl;
}
void test() {
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair(2, 10));
    m.insert(pair<int, int>(3, 8));
    m.insert(pair<int, int>(4, 14));
    if (!m.empty()) {
        cout << m.size() << endl;
        Print(m);
        m.erase(m.begin());
        // depend on the key
        m.erase(2);
        Print(m);
        map<int, int>::iterator pos = m.find(3);
        cout << (*pos).first << " " << (*pos).second << endl;
        cout << m.count(4);
    }

    map<int, int> m2(m);
    m2.swap(m);
    m.clear();
    Print(m);
    Print(m2);
}

class Compare {
public:
    bool operator()(int v1, int v2) { return v1 > v2; }
};
// map sort
void test1() {
    map<int, int, Compare> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair(2, 10));
    m.insert(pair<int, int>(3, 8));
    m.insert(pair<int, int>(4, 14));
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << (*it).first << " " << (*it).second << endl;
    }
}
int main(int argc, char *argv[]) {
    /* test(); */
    test1();
    return 0;
}
