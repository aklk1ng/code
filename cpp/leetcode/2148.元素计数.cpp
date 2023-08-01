#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  int countElement(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int min = nums[0];
    int max = nums[nums.size() - 1];
    int res = 0;
    for (int i = 1; i < nums.size() - 1; i++)
      if (nums[i] > min && nums[i] < max)
        res++;
    return res;
  }
};
