#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int mod = 998244353;

void solve() {
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;

  auto add = [&](int a, int b) {
    a += b;
    if (a < 0) {
      a += mod;
    } else if (a >= mod) {
      a -= mod;
    }
    return a;
  };
  int pw = 1, res = 0, ans = 0;
  for (int i = 0; i < m; i++) {
    if (i < n && s[n - i - 1] == '1') {
      res = add(res, pw);
    }
    if (t[m - i - 1] == '1') {
      ans = add(ans, res);
    }
    pw = add(pw, pw);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
