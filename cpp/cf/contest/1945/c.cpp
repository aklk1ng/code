#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::string a;
  std::cin >> a;

  std::vector<int> suf(n + 1);
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = suf[i + 1] + (a[i] == '1');
  }
  int pref = 0, ans = -1, d = n * 2, t = (n + 1) / 2;
  for (int i = 0; i <= n; i++) {
    if (pref >= (i + 1) / 2 && suf[i] >= (n - i + 1) / 2 &&
        std::abs(n - 2 * i) < d) {
      d = std::abs(n - 2 * i);
      ans = i;
    }
    if (i != n) {
      pref += a[i] == '0';
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
