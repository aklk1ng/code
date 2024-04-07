#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> freq(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    freq[u]++;
    freq[v]++;
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += freq[i] == 1;
  }
  std::cout << (ans + 1) / 2 << '\n';
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
