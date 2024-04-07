#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n;i++) {
    std::cin >> a[i];
  }

  for (int i = 0; i < n - 2; i++) {
    if (a[i] < 0) {
      std::cout << "NO\n";
      return;
    }
    int op = a[i];
    a[i] -= op;
    a[i + 1] -= 2 * op;
    a[i + 2] -= op;
  }

  if (a[n - 1] || a[n - 2]) {
    std::cout << "NO\n";
  } else {
    std::cout << "YES\n";
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
