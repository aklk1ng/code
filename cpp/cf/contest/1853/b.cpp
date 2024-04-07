#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, k;
  std::cin >> n >> k;

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int sec = n;
    int fst = i;
    bool ok = true;
    for (int j = 0; j < k - 2; j++) {
      int fx = fst;
      fst = sec - fx;
      sec = fx;
      ok &= fst <= sec;
      ok &= std::min(fst, sec) >= 0;
      if (!ok) {
        break;
      }
    }
    if (ok) {
      ans++;
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
