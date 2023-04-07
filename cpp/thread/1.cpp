#include <chrono>
#include <iostream>
#include <thread>
using namespace std;

void func(int num, string str) {
  for (int i = 0; i < 10; i++) {
    cout << i << num << str << endl;
  }
}

void func1() {
  for (int i = 0; i < 10; i++) {
    cout << i << endl;
  }
}

int main(int argc, char *argv[]) {
  // main thread | thread t1 | thread t2
  cout << this_thread::get_id() << endl;
  thread t1(func, 520, "i love you");
  thread t2(func1);
  cout << t1.get_id() << endl;
  cout << t2.get_id() << endl;
  t1.join();
  t2.join();
  return 0;
}
