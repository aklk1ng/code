#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int rangeSum(vector<int> &nums, int n, int left, int right) {
    const int mod = 1e9 + 7;
    int len = n * (n + 1) / 2;
    vector<int> res(len);
    int idx = 0;
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = i; j < n; j++) {
        sum += nums[j];
        res[idx++] = sum;
      }
    }

    sort(res.begin(), res.end());
    int ans = 0;
    for (int i = left - 1; i < right; i++) {
      ans = (ans + res[i]) % mod;
    }
    return ans;
  }
};
