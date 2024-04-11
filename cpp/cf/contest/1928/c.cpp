#include <bits/stdc++.h>
typedef long long ll;
const int mod = 998244353;

void solve() {
  int n, x;
  std::cin >> n >> x;

  auto cal = [&](int a) {
    std::unordered_set<int> v;
    for (int i = 1; i * i <= a; i++) {
      if (a % i == 0) {
        if (i % 2 == 0) {
          v.insert(i);
        }
        if ((a / i) % 2 == 0) {
          v.insert(a / i);
        }
      }
    }
    std::unordered_set<int> res;
    for (auto &e : v) {
      res.insert(1 + e / 2);
    }
    return res;
  };
  auto v = cal(n - x);
  for (auto &e : cal(n + x - 2)) {
    v.insert(e);
  }

  int ans = 0;
  for (auto &e : v) {
    if (e >= x) {
      ans++;
    }
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
