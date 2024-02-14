#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  ll sum = std::accumulate(a.begin(), a.end(), 0LL);
  std::vector<ll> cur(2);
  for (int i = 0; i < n; i++) {
    cur[i % 2] += a[i] - 1;
  }
  for (int j = 0; j < 2; j++) {
    if (2 * cur[j] > sum) {
      continue;
    }
    for (int i = 0; i < n; i++) {
      if (i % 2 == j) {
        a[i] = 1;
      }
    }
    break;
  }

  for (auto &e : a) {
    std::cout << e << " \n"[e == a.back()];
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (true) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
