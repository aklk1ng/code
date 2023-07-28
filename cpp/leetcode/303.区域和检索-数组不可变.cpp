#include <bits/stdc++.h>

using namespace std;

class NumArray {
public:
  NumArray(vector<int> &nums) {
    int n = nums.size();
    sums.resize(n + 1);
    for (int i = 0; i < n; i++) {
      sums[i + 1] = sums[i] + nums[i];
    }
  }

  int sumRange(int left, int right) { return sums[right + 1] - sums[left]; }

private:
  vector<int> sums;
};
