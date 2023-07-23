#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  int majorityElement(vector<int> &nums) {
    unordered_map<int, int> map;
    int majority = 0, cnt = 0;
    for (auto &num : nums) {
      map[num]++;
      if (map[num] > cnt) {
        majority = num;
        cnt = map[num];
      }
    }
    return majority;
  }
};
