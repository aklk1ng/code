#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> arrayRankTransform(vector<int> &arr) {
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    vector<int> res(arr.size());
    unordered_map<int, int> map;

    for (auto ele : sorted)
      if (!map.count(ele))
        map[ele] = map.size() + 1;

    for (int i = 0; i < arr.size(); i++)
      res[i] = map[arr[i]];
    return res;
  }
};
