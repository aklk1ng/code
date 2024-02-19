#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;

  bool ok = false;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      ok = true;
      if (i >= n / 2) {
        std::cout << "1 " << i + 1 << ' ' << "1 " << i << '\n';
        break;
      } else {
        std::cout << i + 2 << ' ' << n << ' ' << i + 1 << ' ' << n << '\n';
        break;
      }
    }
  }
  if (!ok) {
    std::cout << "1 " << n - 1 << ' ' << 2 << ' ' << n << '\n';
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
