#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> frequencySort(vector<int> &nums) {
    unordered_map<int, int> map;
    for (auto &num : nums)
      map[num]++;

    sort(nums.begin(), nums.end(), [&](const int a, const int b) {
      if (map[a] != map[b])
        return map[a] < map[b];
      else
        return a > b;
    });
    return nums;
  }
};
