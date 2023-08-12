#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int countBalls(int lowLimit, int highLimit) {
    int res = 0;
    unordered_map<int, int> cnt;

    for (int i = lowLimit; i <= highLimit; i++) {
      int sum = 0, tmp = i;
      while (tmp) {
        sum += tmp % 10;
        tmp /= 10;
      }

      cnt[sum]++;
      res = max(res, cnt[sum]);
    }

    return res;
  }
};
