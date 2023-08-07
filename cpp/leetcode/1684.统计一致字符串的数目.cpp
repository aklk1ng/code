#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int countConsistentStrings(string allowed, vector<string> &words) {
    int hash[26] = {0};
    for (auto &i : allowed)
      hash[i - 'a']++;
    int res = 0;
    for (auto &word : words) {
      bool flag = true;

      for (auto &i : word)
        if (hash[i - 'a'])
          continue;
        else {
          flag = false;
          break;
        }
      if (flag)
        res++;
    }
    return res;
  }
};

class Solution2 {
public:
  int countConsistentStrings(string allowed, vector<string> &words) {
    int mask = 0;
    for (auto &i : allowed)
      mask |= 1 << (i - 'a');

    int res = 0;

    for (auto &word : words) {
      int mask1 = 0;
      for (auto &i : word)
        mask1 |= 1 << (i - 'a');
      if ((mask1 | mask) == mask)
        res++;
    }
    return res;
  }
};
