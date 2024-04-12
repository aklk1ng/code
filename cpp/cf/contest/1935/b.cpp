#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  std::vector<int> cnt1(n + 1), cnt2(n + 1);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    cnt2[a[i]]++;
  }

  int mx1 = 0, mx2 = 0;
  while (cnt2[mx2]) {
    mx2++;
  }
  for (int i = 0; i < n; i++) {
    cnt1[a[i]]++;
    if (--cnt2[a[i]] == 0 && mx2 > a[i]) {
      mx2 = a[i];
    }
    while (mx2 && !cnt2[mx2 - 1]) {
      mx2--;
    }
    while (cnt1[mx1]) {
      mx1++;
    }
    if (mx1 == mx2) {
      std::cout << "2\n";
      std::cout << 1 << ' ' << i + 1 << '\n';
      std::cout << i + 2 << ' ' << n << '\n';
      return;
    }
  }
  std::cout << "-1\n";
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
