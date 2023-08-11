#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string reformatNumber(string number) {
    string s;
    for (auto &c : s)
      if (isdigit(c))
        s += c;

    string res;
    int n = s.size();
    int i = 0;
    for (; n - i > 4; i += 3) {
      res += s.substr(i, 3) + "-";
    }

    if (n - i == 4)
      res += s.substr(i, 2) + "-" + s.substr(i + 2, 2);
    else
      res += s.substr(i, n - i);

    return res;
  }
};
