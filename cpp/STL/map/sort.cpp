#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define CEHUA 0
#define MEISHU 1
#define YANFA 2
class Worker {
public:
    string m_name;
    int m_money;
};
void createworker(vector<Worker> &v) {
    string nameseed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++) {
        Worker worker;
        worker.m_name = "Worker";
        worker.m_name += nameseed[i];
        worker.m_money = rand() % 10000 + 10000;

        v.push_back(worker);
    }
}
void setGroup(vector<Worker> &v, multimap<int, Worker> &m) {
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
        int deptID = rand() % 3;
        m.insert(make_pair(deptID, *it));
    }
}

void showWorker(multimap<int, Worker> &m) {
    cout << "cehua:" << endl;
    multimap<int, Worker>::iterator pos = m.find(CEHUA);
    int count = m.count(CEHUA);
    int index = 0;
    for (; pos != m.end() && index < count; pos++, index++) {
        cout << pos->second.m_name << " " << pos->second.m_money << endl;
    }
    cout << "-------------------" << endl;
    cout << "meishu:" << endl;
    count = m.count(MEISHU);
    pos = m.find(MEISHU);
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++) {
        cout << pos->second.m_name << " " << pos->second.m_money << endl;
    }
    cout << "-------------------" << endl;
    cout << "yanfa:" << endl;
    count = m.count(YANFA);
    pos = m.find(YANFA);
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++) {
        cout << pos->second.m_name << " " << pos->second.m_money << endl;
    }
}

void test() {
    srand((unsigned int)time(NULL));
    vector<Worker> vworker;
    createworker(vworker);
    multimap<int, Worker> mworker;
    setGroup(vworker, mworker);
    showWorker(mworker);
    /* for (vector<Worker>::iterator it =vworker.begin(); it != vworker.end();
     * it++) { */
    /*     cout << it->m_name << " " << it->m_money << endl; */
    /* } */
}

int main(int argc, char *argv[]) {
    test();
    return 0;
}
