#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int n;
  string num;
  vector<vector<int>> list;
  bool isAdditiveNumber(string _num) {
    n = _num.size();
    num = _num;
    return dfs(0);
  }
  bool dfs(int u) {
    int m = list.size();
    if (u == n)
      return m >= 3;
    int max = num[u] == '0' ? u + 1 : n;
    vector<int> cur;
    for (int i = u; i < max; i++) {
      cur.insert(cur.begin(), num[i] - '0');
      if (m < 2 || check(list[m - 2], list[m - 1], cur)) {
        list.push_back(cur);
        if (dfs(i + 1))
          return true;
        list.pop_back();
      }
    }
    return false;
  }
  bool check(vector<int> &a, vector<int> &b, vector<int> &c) {
    vector<int> ans;
    int t = 0;
    for (int i = 0; i < a.size() || i < b.size(); i++) {
      if (i < a.size())
        t += a[i];
      if (i < b.size())
        t += b[i];
      ans.push_back(t % 10);
      t /= 10;
    }
    if (t)
      ans.push_back(1);
    bool ok = (c.size() == ans.size());
    for (int i = 0; i < c.size() && ok; i++)
      if (c[i] != ans[i])
        ok = false;

    return ok;
  }
};
