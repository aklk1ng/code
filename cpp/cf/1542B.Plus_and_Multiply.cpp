#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, a, b;
  std::cin >> n >> a >> b;

  if (a == 1) {
    if ((n - 1) % b == 0) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  } else {
    ll t = 1;
    bool flag = false;
    while (t <= n) {
      if (t % b == n % b) {
        flag = true;
        break;
      }
      t *= a;
    }
    std::cout << (flag ? "YES" : "NO") << '\n';
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
