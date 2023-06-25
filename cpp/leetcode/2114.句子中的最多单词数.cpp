#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  int mostWordsFound(vector<string> &sentences) {
    int res = 0;
    for (string &sentence : sentences) {
      int cnt = count(sentence.begin(), sentence.end(), ' ') + 1;
      res = max(res, cnt);
    }
    return res;
  }
};
