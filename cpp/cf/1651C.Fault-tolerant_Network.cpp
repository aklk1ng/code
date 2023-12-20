#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  auto cal = [&](const vector<int> &v, int cur) {
    int tmp = 1e9 + 10, pos = -1;
    for (int i = 0; i < n; i++) {
      if (tmp > abs(cur - v[i])) {
        tmp = abs(cur - v[i]);
        pos = i;
      }
    }
    return pos;
  };
  ll bst = 10LL * 1e9;
  vector<int> t1 = {0, cal(b, a[0]), n - 1};
  vector<int> t2 = {0, cal(b, a[n - 1]), n - 1};
  for (auto &e1 : t1) {
    for (auto &e2 : t2) {
      ll ans = (ll)abs(a[0] - b[e1]) + abs(a[n - 1] - b[e2]);
      if (e1 > 0 && e2 > 0) {
        ans += abs(b[0] - a[cal(a, b[0])]);
      }
      if (e1 < n - 1 && e2 < n - 1) {
        ans += abs(b[n - 1] - a[cal(a, b[n - 1])]);
      }
      bst = min(bst, ans);
    }
  }
  cout << bst << '\n';
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
