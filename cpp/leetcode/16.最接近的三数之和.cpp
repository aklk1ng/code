#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int ans = 0;
    int best = INT_MAX;
    for (int i = 0; i < n - 2; i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      int s = nums[i] + nums[i + 1] + nums[i + 2];
      if (s > target) {
        if (s - target < best)
          ans = s;
        break;
      }

      s = nums[i] + nums[n - 2] + nums[n - 1];
      if (s < target) {
        if (target - s < best) {
          best = target - s;
          ans = s;
        }
        continue;
      }

      int j = i + 1, k = n - 1;
      while (j < k) {
        int s = nums[i] + nums[j] + nums[k];
        if (s == target)
          return s;
        else if (s > target) {
          if (s - target < best) {
            best = s - target;
            ans = s;
          }
          k--;
          while (j < k && nums[k] == nums[k + 1])
            k--;
        } else {
          if (target - s < best) {
            best = target - s;
            ans = s;
          }
          j++;
          while (j < k && nums[j] == nums[j - 1])
            j++;
        }
      }
    }
    return ans;
  }
};
