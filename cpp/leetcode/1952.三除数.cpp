#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  bool isThree(int n) {
    int s = sqrt(n + 1e-6);
    int cnt = 0;
    for (int i = 1; i <= s; i++) {
      if (n % i == 0) {
        cnt++;
        if (i != n / i)
          cnt++;
        if (cnt > 3)
          return false;
      }
    }
    return cnt == 3;
  }
};
