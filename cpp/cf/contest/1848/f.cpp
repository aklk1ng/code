#include <bits/stdc++.h>
typedef long long ll;

std::vector<int> a;

int solve(int n) {
  if (n == 1) {
    if (a[0] == 0) {
      return 0;
    } else {
      return 1;
    }
  }

  bool ok = true;
  for (int i = 0; i < n / 2; i++) {
    if (a[i] != a[i + n / 2]) {
      ok = false;
    }
  }

  if (ok) {
    return solve(n / 2);
  }
  for (int i = 0; i < n / 2; i++) {
    a[i] ^= a[i + n / 2];
  }
  return n / 2 + solve(n / 2);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (false) {
    std::cin >> T;
  }
  int n;
  std::cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  while (T--) {
    std::cout << solve(n);
  }

  return 0;
}
