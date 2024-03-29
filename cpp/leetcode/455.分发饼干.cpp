#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int index = s.size() - 1;
    int res = 0;
    for (int i = g.size() - 1; i >= 0; i--) {
      if (index >= 0 && s[index] >= g[i]) {
        index--;
        res++;
      }
    }
    return res;
  }
};

class Solution2 {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int index = 0;
    for (int i = 0; i < s.size(); i++) {
      if (index < g.size() && g[index] <= s[i])
        index++;
    }
    return index;
  }
};
