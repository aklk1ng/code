#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int MoreThanHalfNum_Solution(vector<int> &numbers) {
    int n = numbers.size();
    int cond = -1, cnt = 0;
    for (int num : numbers) {
      if (cnt == 0) {
        cond = num;
        cnt++;
      } else {
        if (cond == num)
          cnt++;
        else
          cnt--;
      }
    }
    cnt = 0;
    for (int num : numbers) {
      if (cond == num)
        cnt++;
    }
    if (cnt > n / 2)
      return cond;
    return -1;
  }
};

class Solution2 {
public:
  int MoreThanHalfNum_Solution(vector<int> &numbers) {
    int n = numbers.size();
    unordered_map<int, int> hash;
    for (int num : numbers)
      hash[num]++;
    for (auto &[num, cnt] : hash)
      if (cnt > n / 2)
        return num;
    return -1;
  }
};
