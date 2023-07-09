#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  int heightChecker(vector<int> &heights) {
    vector<int> expected = heights;
    sort(expected.begin(), expected.end());
    int res = 0;

    for (int i = 0; i < heights.size(); i++)
      if (expected[i] != heights[i])
        res++;

    return res;
  }
};
