#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n;
  std::cin >> n;

  std::vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::set<int> s;
  for (int i = 0; i < n; i++) {
    s.insert(i);
  }

  std::vector<int> b(n), sz(n);
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
    b[i]--;
    if (b[i] == -2) {
      continue;
    }
    sz[b[i]]++;
    if (sz[b[i]] == 1) {
      s.erase(b[i]);
    }
  }

  ll sum = 0;
  std::vector ans(2, std::vector<int>());

  while (!s.empty()) {
    int v = *s.begin();
    s.erase(s.begin());
    int w = b[v];
    sum += a[v];
    if (a[v] > 0) {
      if (w >= 0) {
        a[w] += a[v];
      }
      ans[0].push_back(v);
    } else {
      ans[1].push_back(v);
    }
    if (w >= 0) {
      sz[w]--;
      if (sz[w] == 0) {
        s.insert(w);
      }
    }
  }

  std::cout << sum << '\n';
  for (auto &e : ans[0]) {
    std::cout << e + 1 << ' ';
  }
  std::reverse(ans[1].begin(), ans[1].end());
  for (auto &e : ans[1]) {
    std::cout << e + 1 << " \n"[e == ans[1].back()];
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
