#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::string s, f;
  std::cin >> s >> f;

  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] > f[i]) {
      x++;
    }

    if (s[i] < f[i]) {
      y++;
    }
  }

  std::cout << std::max(x, y) << '\n';
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
