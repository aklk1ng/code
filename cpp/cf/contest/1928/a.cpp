#include <bits/stdc++.h>
typedef long long ll;
const int mod = 998244353;

void solve() {
  int a, b;
  std::cin >> a >> b;

  if (a > b) {
    std::swap(a, b);
  }
  if ((a % 2 && b % 2) || (a % 2 && (b == 2 * a))) {
    std::cout << "NO\n";
  } else {
    std::cout << "YES\n";
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
