#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  int maxDistance(vector<int> &colors) {
    int n = colors.size();
    int res = 0;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (colors[i] != colors[j])
          res = max(res, j - i);
    return res;
  }
};
