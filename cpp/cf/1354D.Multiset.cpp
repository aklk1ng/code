#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n), k(q);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < q; i++) {
    cin >> k[i];
  }
  auto len = [&](int x) {
    int res = 0;
    for (auto &e : a) {
      if (e <= x) {
        res++;
      }
    }
    for (auto &e : k) {
      if (e > 0 && e <= x) {
        res++;
      }
      if (e < 0 && abs(e) <= res) {
        res--;
      }
    }
    return res;
  };
  if (len(1e9) == 0) {
    cout << 0 << '\n';
    return;
  }
  int l = 0, r = 1e6 + 1;
  while (l + 1 != r) {
    int m = (l + r) / 2;
    if (len(m) > 0) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << r << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  if (false) {
    cin >> tt;
  }
  while (tt--) {
    solve();
  }

  return 0;
}
