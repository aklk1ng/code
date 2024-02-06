#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 5;

void solve() {
  std::mt19937 rnd(time(NULL));
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::pair<int, int>> b(m);
  std::vector<std::vector<int>> lf(n), rg(n);
  for (int i = 0; i < m; i++) {
    std::cin >> b[i].first >> b[i].second;
    b[i].first--, b[i].second--;
    lf[b[i].second].push_back(b[i].first);
    rg[b[i].first].push_back(b[i].second);
  }

  std::vector<int> v(n, -INF), add(n + 1);
  int mi = a[0];
  for (int i = 0; i < n; i++) {
    v[i] = std::max(v[i], a[i] - mi);
    for (auto &l : lf[i]) {
      for (int j = l; j <= i; j++) {
        add[j]--;
        mi = std::min(mi, a[j] + add[j]);
      }
    }
    mi = std::min(mi, a[i] + add[i]);
  }
  add.assign(n + 1, 0);
  mi = a[n - 1];
  for (int i = n - 1; i >= 0; i--) {
    v[i] = std::max(v[i], a[i] - mi);
    for (auto &r : rg[i]) {
      for (int j = i; j <= r; j++) {
        add[j]--;
        mi = std::min(mi, a[j] + add[j]);
      }
    }
    mi = std::min(mi, a[i] + add[i]);
  }

  int ans = *std::max_element(v.begin(), v.end());
  std::vector<int> res;
  for (int i = 0; i < n; i++) {
    if (v[i] == ans) {
      for (int j = 0; j < m; j++) {
        if (!(b[j].first <= i && i <= b[j].second)) {
          res.push_back(j);
        }
      }
      break;
    }
  }
  std::cout << ans << '\n' << res.size() << '\n';
  std::shuffle(res.begin(), res.end(), rnd);
  for (auto &e : res) {
    std::cout << e + 1 << " \n"[e == res.back()];
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
