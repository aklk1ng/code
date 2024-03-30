#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> P(n);
  for (int i = 0; i < n; i++) {
    std::cin >> P[i];
  }
  std::vector<int> Q(n + 1);
  for (int i = 0; i < n; i++) {
    Q[P[i]] = i;
  }
  int q;
  std::cin >> q;
  while (q--) {
    int a, b;
    std::cin >> a >> b;
    if (Q[a] < Q[b]) {
      std::cout << a << '\n';
    } else {
      std::cout << b << '\n';
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
