#include <bits/stdc++.h>
typedef long long ll;

#define c(x, n) ((x) ^ (n - 1))

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n / 2), b(n / 2);
  if (!k) {
    for (int i = 0; i < n / 2; i++) {
      a[i] = i;
      b[i] = c(i, n);
    }
  }
  if (k > 0 && k < n - 1) {
    int mi = std::min(k, c(k, n));
    for (int i = 0; i < n / 2; i++) {
      if (i && i != mi) {
        a[i] = i;
        b[i] = c(i, n);
      }
    }
    a[0] = 0;
    b[0] = c(k, n);
    a[mi] = k;
    b[mi] = n - 1;
  }
  if (k == n - 1) {
    if (n == 4) {
      std::cout << "-1\n";
      return;
    }
    a[0] = n - 2;
    b[0] = n - 1;
    a[1] = 1;
    b[1] = n - 3;
    a[2] = 0;
    b[2] = 2;
    for (int i = 3; i < n / 2; i++) {
      a[i] = i;
      b[i] = c(i, n);
    }
  }
  for (int i = 0; i < n / 2; i++) {
    std::cout << a[i] << ' ' << b[i] << '\n';
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
