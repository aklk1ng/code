#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minPartitions(string n) {
    int max = 0;
    for (char s : n)
      if (s - '0' > max)
        max = s - '0';
    return max;
  }
};
