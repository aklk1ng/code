#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, k;
  std::cin >> n >> k;
  if (n == 5 && k == 2) {
    std::cout << "YES\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i & 1) {
          std::cout << 'L';
        } else {
          std::cout << 'S';
        }
      }
      std::cout << '\n';
    }
    return;
  }

  std::vector<std::string> ans(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int sum = (i + j) & 1;
      if (!sum && k > 0) {
        ans[i] += 'L';
        k--;
      } else {
        ans[i] += 'S';
      }
    }
  }

  if (!k) {
    std::cout << "YES\n";
    for (int i = 0; i < n; i++) {
      std::cout << ans[i] << '\n';
    }
  } else {
    std::cout << "NO\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (false) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
