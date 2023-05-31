#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  vector<bool> prefixDivBy5(vector<int> &nums) {
    int sum = 0;
    vector<bool> res;
    for (int i = 0; i < nums.size(); i++) {
      sum = (sum << 1) + nums[i];
      sum %= 5;
      res.push_back(!sum);
    }
    return res;
  }
};
