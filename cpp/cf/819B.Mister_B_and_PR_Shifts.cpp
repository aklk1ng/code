#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;
const int N = 1e6 + 5;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> p(n);
  for (int i = 0; i < n; i++) {
    std::cin >> p[i];
  }

  std::vector<ll> sum(N), df(N), res(N);
  auto add = [&](int l, int r, int k, int b) {
    if (l > r) {
      return;
    }
    sum[l] += b;
    df[l] += k;

    sum[r + 1] -= b + k * 1LL * (r - l);
    df[r] -= k;
  };
  auto cal = [&]() {
    ll cur = 0;
    for (int i = 0; i < n; i++) {
      sum[i] += cur;
      cur += df[i];
    }
    ll sm = 0;
    for (int i = 0; i < n; i++) {
      sm += sum[i];
      res[i] += sm;
    }
  };
  for (int i = 0; i < n; i++) {
    int c1 = i + 1, p1 = 0;
    int c2 = n, p2 = p1 + c2 - c1;
    int c3 = i, p3 = p2 + c3;

    if (p[i] <= c3) {
      add(p1, p2, 1, c1 - p[i]);
      add(p2 + 1, p2 + p[i], -1, p[i] - 1);
      add(p2 + p[i] + 1, p3, 1, 1);
    } else {
      add(p1, p1 + p[i] - c1, -1, p[i] - c1);
      add(p1 + p[i] - c1 + 1, p2, 1, 1);
      add(p2 + 1, p3, -1, p[i] - 1);
    }
  }
  cal();

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (res[ans] > res[i]) {
      ans = i;
    }
  }
  std::cout << res[ans] << ' ' << ans << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (false) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
