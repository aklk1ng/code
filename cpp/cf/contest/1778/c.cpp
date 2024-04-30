#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::string a, b;
  std::cin >> a >> b;

  std::unordered_set<char> u;
  for (auto &e : a) {
    u.insert(e);
  }
  std::string list;
  for (auto &e : u) {
    list.push_back(e);
  }
  k = std::min(k, (int)u.size());
  ll ans = 0;
  std::vector<bool> vis(26);
  auto count = [&]() {
    ll res = 0, cnt = 0;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] == b[i] || vis[a[i] - 'a']) {
        cnt++;
      } else {
        res += cnt * (cnt + 1) / 2;
        cnt = 0;
      }
    }
    res += cnt * (cnt + 1) / 2;
    return res;
  };
  auto cal = [&](auto self, int pos, int cnt) -> void {
    if (cnt > k) {
      return;
    }
    if (pos == list.size()) {
      if (cnt == k) {
        ans = std::max(ans, count());
      }
      return;
    }
    self(self, pos + 1, cnt);
    vis[list[pos] - 'a'] = 1;
    self(self, pos + 1, cnt + 1);
    vis[list[pos] - 'a'] = 0;
  };
  cal(cal, 0, 0);
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
