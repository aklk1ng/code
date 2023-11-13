#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, m;
  ll k;
  cin >> n >> m >> k;
  vector<tuple<int, int, ll>> edges(m);
  for (auto &[u, v, cost] : edges) {
    cin >> u >> v >> cost;
    u--, v--;
  }

  basic_string<bool> vis(m, false);
  ranges::fill(vis | views::take(n - 1), true);
  ranges::reverse(vis);

  vector<int> uf(n), sz(n, 1);
  const auto find{[&uf](auto i) {
    while (i != uf[i]) {
      i = uf[i] = uf[uf[i]];
    }
    return i;
  }};
  const auto unite{[&uf, &sz, find](auto i, auto j) {
    i = find(i);
    j = find(j);
    if (i == j) {
      return false;
    }
    if (sz[i] < sz[j]) {
      swap(i, j);
    }
    sz[i] += sz[j];
    uf[j] = i;
    return true;
  }};

  ll ans{k};
  const auto chmin{[](auto &&x, const auto &y) {
    if (x > y) {
      x = y;
    }
    return x;
  }};

  do {
    chmin(ans, [&] {
      iota(uf.begin(), uf.end(), 0);
      ranges::fill(sz, 1);

      ll cost_sum{};
      for (const auto &i : views::iota(0, m)) {
        if (vis[i]) {
          const auto &[u, v, cost]{edges[i]};
          if (!unite(u, v)) {
            return k;
          }
          cost_sum += cost;
        }
      }
      return cost_sum % k;
    }());
  } while (ranges::next_permutation(vis).found);
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
