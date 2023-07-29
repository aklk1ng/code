#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  bool canBeIncreasing(vector<int> &nums) {
    int n = nums.size();
    auto check = [&](const int idx) -> bool {
      for (int i = 1; i < n - 1; i++) {
        int prev = i - 1;
        if (prev >= idx)
          prev++;
        int cur = i;
        if (cur >= idx)
          cur++;

        if (nums[cur] <= nums[prev])
          return false;
      }
      return true;
    };

    for (int i = 1; i < n; i++) {
      if (nums[i] <= nums[i - 1])
        return check(i - 1) || check(i);
    }
    return true;
  }
};
