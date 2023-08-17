// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long

int sg(int x, int y) {
  if (x > y)
    std::swap(x, y);
  if (x == y)
    return 0;
  if (y > 2 * x)
    return 1;

  return !sg(x, (y - 1) / 2);
}

void solve2() {
  int n, m;
  std::cin >> n >> m;
  if (n > m)
    std::swap(n, m);
  std::cout << (sg(n, m) ? "Alice" : "Bob") << std::endl;
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  int ans = 1;
  while (1) {
    if (n > 2 * m || m > 2 * n)
      break;
    if (n > m)
      n = (n - 1) / 2;
    else
      m = (m - 1) / 2;
    ans ^= 1;
  }
  std::cout << (ans ? "Alice" : "Bob") << std::endl;
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
