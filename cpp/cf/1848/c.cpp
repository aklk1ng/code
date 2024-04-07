#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }

  auto gcd = [&](auto self, int x, int y) {
    if (!x) {
      return 0;
    }
    if (!y) {
      return 1;
    }
    if (x >= y) {
      int r = x % y;
      int k = x / y;
      if (k % 2) {
        return self(self, y, r) + k + k / 2;
      } else {
        return self(self, r, y) + k + k / 2;
      }
    }
    return 1 + self(self, y, std::abs(x - y));
  };
  auto cal = [&](auto self, int x, int y) {
    if (!x) {
      return 0;
    }
    if (!y) {
      return 1;
    }
    return 1 + self(self, y, std::abs(x - y));
  };
  std::set<int> cnt;
  for (int i = 0; i < n; i++) {
    if (!a[i] && !b[i]) {
      continue;
    }
    cnt.insert(gcd(gcd, a[i], b[i]) % 3);
  }

  std::cout << (cnt.size() <= 1 ? "YES" : "NO") << '\n';
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
