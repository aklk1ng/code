#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minSwaps(string s) {
    int cnt, mincnt = 0;
    for (char ch : s) {
      if (ch == '[')
        cnt++;
      else {
        cnt--;
        mincnt = min(mincnt, cnt);
      }
    }
    return (-mincnt + 1) / 2;
  }
};
