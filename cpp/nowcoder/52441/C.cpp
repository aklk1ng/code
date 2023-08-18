// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long

const int N = 20;
int a[N], b[N], c[N], x[N], y[N];
ll res = 0;
bool over[N];
int n, t, p;

void f(int time, int cnt, ll score) {
  if (cnt == n) {
    res = std::max(res, score);
    return;
  }

  res = std::max(res, score);
  for (int i = 0; i < n; i++) {
    if (time + x[i] <= t && !over[i]) {
      over[i] = true;
      f(time + x[i], cnt + 1, score + std::max(c[i], a[i] - (time + x[i]) * b[i] - y[i] * p));
      over[i] = false;
    }
  }
}

void solve() {
  std::cin >> n >> t >> p;
  for (int i = 0; i < n; i++)
    std::cin >> a[i] >> b[i] >> c[i] >> x[i] >> y[i];
  f(0, 0, 0);
  std::cout << res << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
