#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> v(n);
  std::vector<std::pair<int, int>> can(n);
  for (int i = 0; i < n; i++) {
    std::cin >> v[i];
    can[i] = {v[i], i};
  }
  std::vector<int> ord(n);
  for (int i = 0; i < n; i++) {
    std::cin >> ord[i];
    ord[i]--;
  }

  std::sort(can.rbegin(), can.rend());
  ll best = can[0].first, take = 1;
  ll cur, t = 1;
  std::vector<bool> burn(n), vis(n);
  vis[can[0].second] = true;
  for (int i = 0; i < n - 1 && t < n; i++) {
    while (t < n && burn[can[t].second]) {
      t++;
    }
    if (t == n) {
      break;
    }
    vis[can[t].second] = true;
    cur = can[t].first;
    t++;
    burn[ord[i]] = true;

    if (vis[ord[i]]) {
      while (t < n && burn[can[t].second]) {
        t++;
      }
      if (t == n) {
        break;
      }
      vis[can[t].second] = true;
      cur = can[t].first;
      t++;
    }

    if (best < cur * (i + 2)) {
      take = i + 2;
      best = cur * (i + 2);
    }
  }

  std::cout << best << ' ' << take << '\n';
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
