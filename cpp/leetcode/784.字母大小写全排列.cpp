#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<string> res;
  vector<string> letterCasePermutation(string s) {
    int n = s.size();
    function<void(int)> dfs = [&](int i) {
      while (i < n && isdigit(s[i]))
        i++;
      if (i == n) {
        res.push_back(s);
        return;
      }

      // case convert
      s[i] ^= 32;
      dfs(i + 1);
      // case convert
      s[i] ^= 32;
      dfs(i + 1);
    };
    dfs(0);
    return res;
  }
};
