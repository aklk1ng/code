#include <bits/stdc++.h>
typedef long long ll;
const int mod = 998244353;

void solve() {
  int n, c, d;
  std::cin >> n >> c >> d;
  std::vector<ll> a(n * n);
  for (int i = 0; i < n * n; i++) {
    std::cin >> a[i];
  }

  std::sort(a.begin(), a.end());
  std::vector<ll> b(n * n);
  b[0] = a[0];
  for (int i = 1; i < n; i++) {
    b[i] = b[i - 1] + c;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      b[i * n + j] = b[(i - 1) * n + j] + d;
    }
  }
  std::sort(b.begin(), b.end());
  std::cout << (a == b ? "YES" : "NO") << '\n';
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
