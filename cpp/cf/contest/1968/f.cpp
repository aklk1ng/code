#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1);
  std::map<int, std::vector<int>> id;
  id[0].push_back(0);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] ^= a[i - 1];
    id[a[i]].push_back(i);
  }
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    if (a[r] == a[l - 1]) {
      std::cout << "YES\n";
      continue;
    }
    int L = *--std::lower_bound(id[a[l - 1]].begin(), id[a[l - 1]].end(), r);
    int R = *std::lower_bound(id[a[r]].begin(), id[a[r]].end(), l);
    std::cout << (L > R ? "YES" : "NO") << '\n';
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
