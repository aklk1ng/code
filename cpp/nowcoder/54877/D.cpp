// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
const int N = 2e5 + 10;
int a[N], b[N], c[N], d[N];

void solve() {
  int n, m;
  std::cin >> n >> m;

  for (int i = 0; i < n; i++)
    std::cin >> a[i];
  for (int i = 0; i < n; i++)
    std::cin >> c[i];

  for (int i = 0; i < m; i++)
    std::cin >> b[i];
  for (int i = 0; i < m; i++)
    std::cin >> d[i];

  for (int i = 0; i < n; i++) {
    int res = -1;
    for (int j = 0; j < m; j++) {
      if (b[j] >= c[i] && a[i] >= d[j]) {
        res = std::max(res, b[j]);
      }
    }
    std::cout << res << " ";
  }
  std::cout << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
