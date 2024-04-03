#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  ll a, b, m;
  std::cin >> a >> b >> m;
  std::cout << m / a + m / b + 2 << '\n';
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
