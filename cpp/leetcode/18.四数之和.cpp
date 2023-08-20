#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int k = 0; k < nums.size(); k++) {
      if (nums[k] > target && nums[k] >= 0) {
        break;
      }

      // depublication for nums[k]
      if (k > 0 && nums[k] == nums[k - 1]) {
        continue;
      }

      for (int i = k + 1; i < nums.size(); i++) {
        if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0)
          break;

        // depublication for nums[i]
        if (i > k + 1 && nums[i] == nums[i - 1])
          continue;

        int left = i + 1;
        int right = nums.size() - 1;
        while (right > left) {
          if ((long)nums[k] + nums[i] + nums[left] + nums[right] > 0)
            right--;
          else if ((long)nums[k] + nums[i] + nums[left] + nums[right] < 0)
            left++;
          else {
            res.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
            // depublication for nums[right]
            while (right > left && nums[right] == nums[right - 1])
              right--;

            // depublication for nums[left]
            while (right > left && nums[left] == nums[left + 1])
              left++;

            right--;
            left++;
          }
        }
      }
    }
    return res;
  }
};

class Solution2 {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int k = 0; k < n - 3; k++) {
      if (nums[k] > target && nums[k] >= 0)
        break;
      if (k > 0 && nums[k] == nums[k - 1])
        continue;

      for (int i = k + 1; i < n - 2; i++) {
        if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0)
          break;
        if (i > k + 1 && nums[i] == nums[i - 1])
          continue;

        int l = i + 1, r = n - 1;
        while (l < r) {
          long long sum = (long long)nums[k] + nums[i] + nums[l] + nums[r];
          if (sum < target)
            l++;
          else if (sum > target)
            r--;
          else {
            res.push_back(vector<int>{nums[k], nums[i], nums[l], nums[r]});
            r--;
            while (l < r && nums[r] == nums[r + 1])
              r--;
            l++;
            while (l < r && nums[l] == nums[l - 1])
              l++;
          }
        }
      }
    }
    return res;
  }
};
