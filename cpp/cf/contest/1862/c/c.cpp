// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
const int N = 2e5 + 5;
int a[N], b[N];

void solve() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++)
    std::cin >> a[i];
  if (a[1] != n) {
    std::cout << "NO" << '\n';
    return;
  }
  for (int i = 1, j = n; i <= n; i++) {
    while (j >= 1 && a[j] < i)
      j--;
    if (a[i] != j) {
      std::cout << "NO" << '\n';
      return;
    }
  }
  std::cout << "YES" << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
