#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;
const int N = 2e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), f(N);
  vector v(N, vector<int>());
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  auto upd = [&](int pos, int d) {
    for (; pos < N; pos |= pos + 1) {
      f[pos] += d;
    }
  };
  auto get = [&](int pos) {
    int res = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
      res += f[pos];
    }
    return res;
  };
  for (int i = 0; i < n; i++) {
    if (a[i] < N) {
      v[a[i]].push_back(i);
    }
    upd(i, 1);
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int t = min(N - 1, a[i]);
    ans += get(t);
    for (auto &e : v[i]) {
      upd(e, -1);
    }
  }
  for (int i = 0; i < n; i++) {
    if (i <= a[i]) {
      ans--;
    }
  }
  cout << ans / 2 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  if (false) {
    cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
