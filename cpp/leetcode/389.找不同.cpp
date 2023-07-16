#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  char findTheDifference(string s, string t) {
    int sums = 0, sumt = 0;
    for (auto &c : s)
      sums += c;
    for (auto &c : t)
      sumt += c;
    return sumt - sums;
  }
};
