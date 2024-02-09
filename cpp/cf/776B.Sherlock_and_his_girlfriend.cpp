#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 2);
  for (int i = 2; i <= n + 1; i++) {
    if (!a[i]) {
      for (int j = 2 * i; j <= n + 1; j += i) {
        a[j] = 1;
      }
    }
  }
  if (n > 2) {
    std::cout << "2\n";
  } else {
    std::cout << "1\n";
  }
  for (int i = 2; i <= n + 1; i++) {
    if (!a[i]) {
      std::cout << "1 ";
    } else {
      std::cout << "2 ";
    }
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
