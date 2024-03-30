#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;

  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      int p = 2;
      for (int j = 0; j < i; j++) {
        for (int k = j + i; k < n; k += i) {
          if (s[k] != s[j]) {
            p--;
          }
        }
      }
      if (p > 0) {
        std::cout << i << '\n';
        return;
      }

      p = 2;
      for (int j = n - i; j < n; j++) {
        for (int k = j - i; k >= 0; k -= i) {
          if (s[k] != s[j]) {
            p--;
          }
        }
      }
      if (p > 0) {
        std::cout << i << '\n';
        return;
      }
    }
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
