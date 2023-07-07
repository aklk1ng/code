#include <bits/stdc++.h>

using namespace std;

class Allocator {
public:
  int window(int idx, int size, int mID) {
    for (int i = 0; i < size; i++)
      mem[idx + 1] = mID;
    return idx;
  }
  Allocator(int n) {
    this->n = n;
    mem = vector<int>(n);
  }
  int allocate(int size, int mID) {
    if (size > n)
      return -1;

    int sm = 0;
    for (int i = 0; i < size; i++)
      sm += mem[i];
    if (sm == 0)
      return window(0, size, mID);

    for (int i = size; i < n; i++) {
      sm += mem[i] - mem[i - size];
      if (sm == 0)
        return window(i - size + 1, size, mID);
    }
    return -1;
  }

  int free(int mID) {
    int cnt = 0;
    for (int i = 0; i < n; i++)
      if (mem[i] == mID)
        mem[i] = 0, cnt++;
    return cnt;
  }

private:
  vector<int> mem;
  int n;
};
