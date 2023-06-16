#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
    vector<int> res = nums;
    sort(res.begin(), res.end());

    int hash[101];
    for (int i = res.size() - 1; i >= 0; i--)
      hash[res[i]] = i;

    for (int i = 0; i < nums.size(); i++)
      res[i] = hash[nums[i]];

    return res;
  }
};
