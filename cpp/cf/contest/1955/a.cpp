#include <bits/stdc++.h>
typedef long long ll;
const int mod = 998244353;

void solve() {
  int n, a, b;
  std::cin >> n >> a >> b;

  int ans = n * a;
  if (b < 2 * a) {
    ans = (n / 2) * b + (n % 2) * a;
  }
  std::cout << ans << '\n';
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
