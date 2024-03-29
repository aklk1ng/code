#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;

  std::map<int, int> m;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    if (!m[x]) {
      ans++;
      ++m[((1 << 31) - 1) ^ x];
    } else {
      --m[x];
    }
  }

  std::cout << ans << '\n';
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
