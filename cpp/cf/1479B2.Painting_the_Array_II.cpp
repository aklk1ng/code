#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), pos(n + 1, n + 1), nxt(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = n; i >= 0; i--) {
    nxt[i] = pos[a[i]];
    pos[a[i]] = i;
  }
  int x = 0, y = 0, ans = 0;
  for (int z = 1; z <= n; z++) {
    if (a[x] == a[z]) {
      x = z;
    } else if (a[y] == a[z]) {
      y = z;
    } else if (nxt[x] > nxt[y]) {
      ans++;
      x = z;
    } else {
      ans++;
      y = z;
    }
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
