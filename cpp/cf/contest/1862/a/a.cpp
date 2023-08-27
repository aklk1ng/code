// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n);
  std::string res = "vika";
  int idx = 0;
  for (int i = 0; i < n; i++)
    std::cin >> a[i];

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (a[j][i] == res[idx]) {
        idx++;
        if (idx == 4) {
          std::cout << "YES" << '\n';
          return;
        }
        break;
      }
    }
  }
  std::cout << "NO" << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
