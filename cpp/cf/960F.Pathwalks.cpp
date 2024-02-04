#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::map<int, int>> s(n + 1);

  auto get = [&](int a, int w) {
    auto it = s[a].lower_bound(w);
    if (it == s[a].begin()) {
      return 1;
    }
    it--;
    return (it->second) + 1;
  };

  int ans = 0;
  while (m--) {
    int a, b, w;
    std::cin >> a >> b >> w;
    int val = get(a, w);
    if (get(b, w + 1) > val) {
      continue;
    }
    s[b][w] = std::max(s[b][w], val);
    auto it = s[b].upper_bound(w);
    while (!(it == s[b].end() || it->second > val)) {
      it = s[b].erase(it);
    }
    ans = std::max(ans, val);
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
