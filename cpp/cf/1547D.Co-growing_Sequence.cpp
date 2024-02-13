#include <bits/stdc++.h>
typedef long long ll;

#define f(x, y) ((x) & (~y))

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::vector<int> ans(n);
  for (int i = 1; i < n; i++) {
    ans[i] = f(ans[i - 1] ^ a[i - 1], a[i]);
  }
  for (auto &e : ans) {
    std::cout << e << ' ';
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
