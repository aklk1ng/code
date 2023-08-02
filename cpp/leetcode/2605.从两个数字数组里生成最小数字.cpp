#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minumber(vector<int> &nums1, vector<int> &nums2) {
    int res = 99;

    for (int i : nums1)
      for (int j : nums2)
        if (i == j)
          res = min(res, i);
        else
          res = min({res, 10 * i + j, 10 * j + i});

    return res;
  }
};
