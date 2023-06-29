#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  bool hasGroupsSize(vector<int> &deck) {
    int cnt[10000] = {0};
    for (auto s : deck)
      cnt[s]++;
    int g = -1;
    for (int i = 0; i < 10000; i++) {
      if (cnt[i]) {
        if (~g)
          g = gcd(g, cnt[i]);
        else
          g = cnt[i];
      }
    }
    return g >= 2;
  }
};
