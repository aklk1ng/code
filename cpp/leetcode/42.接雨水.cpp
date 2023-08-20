#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    int n = height.size();
    vector<int> pre(n);
    pre[0] = height[0];
    for (int i = 1; i < n; i++)
      pre[i] = max(pre[i - 1], height[i]);
    vector<int> suf(n);
    suf[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
      suf[i] = max(suf[i + 1], height[i]);

    int ans = 0;
    for (int i = 0; i < n; i++)
      ans += min(pre[i], suf[i]) - height[i];

    return ans;
  }
};

class Solution2 {
public:
  int trap(vector<int> &height) {
    int n = height.size();
    int ans = 0;
    int pre_max = 0;
    int suf_max = 0;
    int l = 0, r = n - 1;
    while (l < r) {
      pre_max = max(pre_max, height[l]);
      suf_max = max(suf_max, height[r]);
      if (pre_max < suf_max) {
        ans += pre_max - height[l];
        l++;
      } else {
        ans += suf_max - height[r];
        r--;
      }
    }
    return ans;
  }
};
