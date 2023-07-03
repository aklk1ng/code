#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  int rearrangerCharacters(string s, string target) {
    unordered_map<char, int> scnt, targetcnt;
    int m = target.size(), n = s.size();
    for (int i = 0; i < m; i++)
      targetcnt[target[i]]++;
    for (int i = 0; i < n; i++)
      if (targetcnt.count(s[i]))
        scnt[s[i]]++;

    int ans = INT_MAX;
    for (auto &[c, count] : targetcnt) {
      int cnt = scnt[c];
      ans = min(ans, cnt / count);
      if (ans == 0)
        return 0;
    }
    return ans;
  }
};
