#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int digit(char s) {
    if (s == 'I')
      return 1;
    else if (s == 'V')
      return 5;
    else if (s == 'X')
      return 10;
    else if (s == 'L')
      return 50;
    else if (s == 'C')
      return 100;
    else if (s == 'D')
      return 500;
    else if (s == 'M')
      return 1000;
    else
      return -1;
  }
  int romanToInt(string s) {
    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
      int value = digit(s[i]);
      if (i < s.size() - 1 && value < digit(s[i + 1]))
        sum -= value;
      else
        sum += value;
    }
    return sum;
  }
};
