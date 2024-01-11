#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> a(n + 1), p(n + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = (s[i - 1] == '+' ? 1 : -1);
  }
  p[0] = 0;
  for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1] + (i % 2 ? a[i] : -a[i]);
  }
  auto cal = [&](int l, int r) {
    if (l > r) {
      return 0;
    }
    return l % 2 ? p[r] - p[l - 1] : p[l - 1] - p[r];
  };
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (cal(l, r) == 0) {
      cout << 0 << '\n';
      continue;
    }
    if ((r - l + 1) % 2 == 0) {
      cout << 2 << '\n';
    } else {
      cout << 1 << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
