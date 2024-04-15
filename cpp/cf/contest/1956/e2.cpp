#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 4);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  auto check = [&]() {
    a[n + 1] = a[1];
    a[n + 2] = a[2];
    a[n + 3] = a[3];
    for (int i = 1; i <= n; i++) {
      if (a[i] && a[i + 1] && a[i + 2] && a[i + 3]) {
        return true;
      }
    }
    return false;
  };
  std::vector<bool> b(n + 1);
  if (n == 2) {
    while (a[1] && a[2]) {
      a[2] = std::max(0, a[2] - a[1]);
      a[1] = std::max(0, a[1] - a[2]);
    }
    b[1] = a[1] > 0;
    b[2] = a[2] > 0;
  } else if (n == 3) {
    while (a[1] && a[2] && a[3]) {
      a[2] = std::max(0, a[2] - a[1]);
      a[3] = std::max(0, a[3] - a[2]);
      a[1] = std::max(0, a[1] - a[3]);
    }
    b[1] = (!a[3] && a[1]);
    b[2] = (!a[1] && a[2]);
    b[3] = (!a[2] && a[3]);
  } else {
    while (check()) {
      for (int i = 1; i <= n; i++) {
        a[i % n + 1] = std::max(0, a[i % n + 1] - a[i]);
      }
    }
    std::fill(b.begin() + 1, b.end(), false);
    auto at = [&](ll x, ll y) {
      ll k = x / y;
      return (2 * x - (k + 1) * y) * k / 2;
    };
    for (int p = 1; p <= n; p++) {
      if (a[p] && a[p % n + 1]) {
        a[p % n + 1] = std::max(0, a[p % n + 1] - a[p]);
      } else {
        break;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (!a[i] && a[i % n + 1]) {
        b[i % n + 1] = true;
        b[(i + 2) % n + 1] =
            (a[(i + 2) % n + 1] > at(a[(i + 1) % n + 1], a[i % n + 1]));
      }
    }
  }

  std::cout << std::count(b.begin(), b.end(), true) << '\n';
  for (int i = 1; i <= n; i++) {
    if (b[i]) {
      std::cout << i << ' ';
    }
  }
  std::cout << '\n';
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
