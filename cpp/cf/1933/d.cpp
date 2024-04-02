#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::sort(a.begin(), a.end());
  if (a[0] != a[1]) {
    std::cout << "YES\n";
  } else {
    bool ok = false;
    for (int i = 1; i < n; i++) {
      if (a[i] % a[0]) {
        ok = true;
      }
    }
    std::cout << (ok ? "YES" : "NO") << '\n';
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
