#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  void backtrack(vector<string> &res, string &cur, int open, int close, int n) {
    if (cur.size() == 2 * n) {
      res.push_back(cur);
      return;
    }
    if (open < n) {
      cur.push_back('(');
      backtrack(res, cur, open + 1, close, n);
      cur.pop_back();
    }
    if (close < open) {
      cur.push_back(')');
      backtrack(res, cur, open, close + 1, n);
      cur.pop_back();
    }
  }
  vector<string> generateParenthsis(int n) {
    vector<string> res;
    string cur;
    backtrack(res, cur, 0, 0, n);
    return res;
  }
};
