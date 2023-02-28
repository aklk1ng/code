#include <iostream>
#include <unordered_map>
using namespace std;

void test() {
  unordered_map<int, int> hash;
  hash.insert(make_pair(1, 1));
  hash.insert(make_pair(2, 3));
  hash.insert(make_pair(3, 5));
  hash.insert(make_pair(5, 7));
  unordered_map<int, int>::iterator pos = hash.find(2);
  cout << (*pos).first << " " << (*pos).second << endl;
}

int main(int argc, char *argv[]) {
  test();
  return 0;
}
