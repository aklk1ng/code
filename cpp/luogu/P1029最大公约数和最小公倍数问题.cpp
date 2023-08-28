// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

void solve() {
  int x, y;
  std::cin >> x >> y;
  int ans = 0;
  for (int i = x; i <= y; i++) {
    int j = x * y / i;
    if (i * j != x * y)
      continue;
    if (gcd(i, j) == x && lcm(i, j) == y)
      ans++;
  }
  std::cout << ans << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
