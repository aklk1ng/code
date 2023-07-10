#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  unordered_map<int, int> map;
  int integerReplacement(int n) {
    if (n == 1)
      return 0;

    if (map.count(n))
      return map[n];

    if (n % 2 == 0)
      return map[n] = 1 + integerReplacement(n / 2);
    else
      return map[n] = 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
  }
};
