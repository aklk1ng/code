#include <bits/stdc++.h>
typedef long long ll;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    std::cin >> v[i].first;
  }
  for (int i = 0; i < n; i++) {
    std::cin >> v[i].second;
  }

  std::sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    std::cout << v[i].first << " \n"[i == n - 1];
  }
  for (int i = 0; i < n; i++) {
    std::cout << v[i].second << " \n"[i == n - 1];
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
