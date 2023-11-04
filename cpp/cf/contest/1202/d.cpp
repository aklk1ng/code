#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  string s, t;
  cin >> s >> t;
  int n = s.size();

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int pos = 0;
      for (int p = 0; p < n; p++) {
        if (i <= p && p <= j) {
          continue;
        }
        if (pos < (int)t.size() && t[pos] == s[p]) {
          pos++;
        }
      }
      if (pos == (int)t.size()) {
        ans = max(ans, j - i + 1);
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
