#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int N;
  std::cin >> N;
  std::vector<int> A(N - 1), B(N - 1);
  std::vector<std::vector<int>> tree(N);
  for (int i = 0; i < N - 1; i++) {
    std::cin >> A[i] >> B[i];
    A[i]--, B[i]--;
    tree[A[i]].push_back(B[i]);
    tree[B[i]].push_back(A[i]);
  }
  std::vector<ll> C(N);
  for (int i = 0; i < N; i++) {
    std::cin >> C[i];
  }

  std::vector<ll> sum_c(N), sum_d(N);
  auto dfs = [&](auto self, int v, int p) -> std::pair<ll, ll> {
    for (const int &u : tree[v]) {
      if (u == p) {
        continue;
      }
      const auto [c, d] = self(self, u, v);
      sum_c[v] += c;
      sum_d[v] += d;
    }
    sum_d[v] += sum_c[v];
    sum_c[v] += C[v];
    return {sum_c[v], sum_d[v]};
  };
  dfs(dfs, 0, -1);
  std::vector<ll> f(N);
  auto reroot = [&](auto self, const int v, const int p, const ll c,
                    const ll d) -> void {
    f[v] = sum_d[v] + d;
    for (const int &u : tree[v]) {
      if (u == p) {
        continue;
      }
      ll nc = c + sum_c[v] - sum_c[u];
      ll nd = d + sum_d[v] - sum_d[u] - sum_c[u] + nc;
      self(self, u, v, nc, nd);
    }
  };
  reroot(reroot, 0, -1, 0, 0);
  std::cout << *std::min_element(f.begin(), f.end()) << '\n';
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
