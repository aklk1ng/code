#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries) {
    int n = queries.size(), sum = 0;
    vector<int> res(n);
    for (int num : nums)
      sum += num % 2 == 0 ? num : 0;
    for (int i = 0; i < n; i++) {
      int val = queries[i][0], idx = queries[i][1];
      if (nums[idx] % 2 == 0)
        sum -= nums[idx];
      nums[idx] += val;
      if (nums[idx] % 2 == 0)
        sum += nums[idx];
      res[i] = sum;
    }
    return res;
  }
};
