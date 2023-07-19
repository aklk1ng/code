#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  int count(int x) {
    int cnt = 0;
    while (x > 0) {
      x &= (x - 1);
      cnt++;
    }
    return cnt;
  }
  vector<int> coutnBits(int n) {
    vector<int> res(n + 1);
    for (int i = 0; i <= n; i++)
      res[i] = count(i);
    return res;
  }
};
