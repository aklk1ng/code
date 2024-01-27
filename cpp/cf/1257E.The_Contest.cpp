#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int k1, k2, k3;
  std::cin >> k1 >> k2 >> k3;
  int n = k1 + k2 + k3;
  std::vector<int> a(n);
  for (int i = 0; i < k1; i++) {
    int x;
    std::cin >> x;
    a[x - 1] = 0;
  }
  for (int i = 0; i < k2; i++) {
    int x;
    std::cin >> x;
    a[x - 1] = 1;
  }
  for (int i = 0; i < k3; i++) {
    int x;
    std::cin >> x;
    a[x - 1] = 2;
  }

  int ans = 0;
  int best = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != 2) {
      ans++;
    }
  }
  std::vector<int> cntl(3), cntr(3);
  for (int i = 0; i < n; i++) {
    cntr[a[i]]++;
  }
  for (int i = 0; i < n; i++) {
    cntl[a[i]]++;
    cntr[a[i]]--;
    best = std::max(best, cntl[0] - cntl[1]);
    ans = std::min(ans, cntr[0] + cntr[1] + cntl[2] + cntl[0] - best);
  }

  std::cout << ans << '\n';
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
