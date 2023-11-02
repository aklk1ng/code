#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  vector<int> p(n);
  iota(p.begin(), p.end(), 1);
  bool ans = true;
  ll l = 0, r = 0;
  while (r < n) {
    while (r < n - 1 && s[r] == s[r + 1]) {
      r++;
    }
    if (l == r) {
      ans = false;
    } else {
      rotate(p.begin() + l, p.begin() + r, p.begin() + r + 1);
    }
    l = r + 1;
    r++;
  }

  if (ans) {
    for (auto &e : p) {
      cout << e << " \n"[e == p.back()];
    }
  } else {
    cout << -1 << '\n';
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
