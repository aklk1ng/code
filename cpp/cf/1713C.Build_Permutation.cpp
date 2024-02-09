#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> ans(n + 1);
  auto cal = [&](auto self, int r) -> void {
    if (r < 0) {
      return;
    }
    int s = std::sqrt(2 * r);
    s *= s;
    int l = s - r;
    self(self, l - 1);
    for (; l <= r; l++, r--) {
      ans[l] = r;
      ans[r] = l;
    }
  };
  cal(cal, n - 1);
  for (int i = 0; i < n; i++) {
    std::cout << ans[i] << " \n"[i == n - 1];
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
