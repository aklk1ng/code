#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  int sum = 0;
  bool ok = false;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    sum += x;
    if (x % 3 == 1) {
      ok = true;
    }
  }
  if (sum % 3 == 0) {
    std::cout << "0\n";
  } else if (sum % 3 == 2) {
    std::cout << "1\n";
  } else {
    std::cout << (ok ? 1 : 2) << '\n';
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
