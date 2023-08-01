#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  int prefixCount(vector<string> &words, string pref) {
    int res = 0;
    for (auto &word : words) {
      if (word.compare(0, pref.size(), pref) == 0)
        res++;
    }
    return res;
  }
};
