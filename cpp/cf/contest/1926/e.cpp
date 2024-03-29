#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> v;
  while (n) {
    v.push_back((n + 1) / 2);
    n /= 2;
  }
  int tot = 0, p = 1;
  for (int &e : v) {
    if (tot < k && k <= tot + e) {
      std::cout << p * (2 * (k - tot) - 1) << '\n';
      return;
    }
    tot += e;
    p *= 2;
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
