#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
    int cur = 0;
    int res = 0;
    sort(boxTypes.begin(), boxTypes.end(),
         [&](const vector<int> &a, const vector<int> &b) { return a[1] > b[1]; });

    for (auto &box : boxTypes) {
      if (truckSize - cur > box[1]) {
        cur += box[1];
        res += box[0] * box[1];
      } else {
        int n = truckSize - cur;
        res += n * box[1];
        break;
      }
    }

    return res;
  }
};
