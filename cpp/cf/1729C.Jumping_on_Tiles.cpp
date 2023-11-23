#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  map<char, vector<int>> m;
  for (int i = 0; i < n; i++) {
    m[s[i]].push_back(i);
  }

  int direct = (s[0] < s[n - 1]) ? 1 : -1;
  vector<int> ans;
  for (char c = s[0]; c != s[n - 1] + direct; c += direct) {
    for (auto &e : m[c]) {
      ans.push_back(e);
    }
  }

  int cost = 0;
  int sz = ans.size();
  for (int i = 1; i < sz; i++) {
    cost += abs(s[ans[i]] - s[ans[i - 1]]);
  }
  cout << cost << ' ' << sz << '\n';
  for (auto &e : ans) {
    cout << e + 1 << " \n"[e == ans.back()];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
