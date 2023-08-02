#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string thousandSeperator(int n) {
    string res;
    int cnt = 0;
    do {
      int cur = n % 10;
      n /= 10;
      cnt++;
      res += to_string(cur);
      if (cnt % 3 == 0 && n)
        res += '.';
    } while (n);
    reverse(res.begin(), res.end());
    return res;
  }
};
