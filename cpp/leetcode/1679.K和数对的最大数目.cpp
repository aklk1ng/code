#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxOperations(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int res = 0;
    int i = 0, j = nums.size() - 1, sum;

    while (i < j) {
      sum = nums[i] + nums[j];
      if (sum == k) {
        res++;
        i++;
        j--;
      } else if (sum > k)
        j--;
      else
        j++;
    }
    return res;
  }
};
