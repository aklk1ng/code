#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, x;
  std::cin >> n >> x;
  std::vector<int> a(n), pre(n);
  std::vector pos(x + 1, std::vector<int>());
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    pos[a[i]].push_back(i);
    pre[i] = std::max(a[i], (i > 0 ? pre[i - 1] : a[i]));
  }

  int p = 1, lst = n + 5;
  for (int i = x; i >= 1; i--) {
    if (pos[i].empty()) {
      p = i;
      continue;
    }
    if (pos[i].back() > lst) {
      break;
    }
    p = i;
    lst = pos[i][0];
  }

  ll ans = 0;
  lst = -1;
  for (int l = 1; l <= x; l++) {
    int r = std::max(l, p - 1);
    if (lst != -1) {
      r = std::max(r, pre[lst]);
    }
    ans += x - r + 1;
    if (!pos[l].empty()) {
      if (pos[l][0] < lst) {
        break;
      }
      lst = pos[l].back();
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
