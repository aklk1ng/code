#include <bits/stdc++.h>

using namespace std;

class MyHashMap {
public:
  MyHashMap() : data(base) {}
  void add(int key, int value) {
    int h = hash(key);
    for (auto it = data[h].begin(); it != data[h].end(); it++) {
      if ((*it).first == key) {
        (*it).second = value;
        return;
      }
    }
    data[h].push_back(make_pair(key, value));
  }

  int get(int key) {
    int h = hash(key);
    for (auto it = data[h].begin(); it != data[h].end(); it++) {
      if ((*it).first == key) return (*it).second;
    }
    return -1;
  }

  void remove(int key) {
    int h = hash(key);
    for (auto it = data[h].begin(); it != data[h].end(); it++) {
      if ((*it).first == key) {
        data[h].erase(it);
        return;
      }
    }
  }
  private:
  vector<list<pair<int, int>>> data;
  static const int base = 7;
  static int hash(int key) { return key % base; }
};
