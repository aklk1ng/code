#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i].first;
    a[i].second = i;
  }

  std::sort(a.begin(), a.end(), std::greater<std::pair<int, int>>());
  std::vector<int> ind(m * k);
  ll sum = 0;
  for (int i = 0; i < m * k; i++) {
    sum += a[i].first;
    ind[i] = a[i].second;
  }
  std::sort(ind.begin(), ind.end());
  std::vector<int> div(k - 1);
  for (int i = 0; i < k - 1; i++) {
    div[i] = ind[(i + 1) * m - 1];
  }
  std::cout << sum << '\n';
  for (auto &e : div) {
    std::cout << e + 1 << " \n"[e == div.back()];
  }
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
