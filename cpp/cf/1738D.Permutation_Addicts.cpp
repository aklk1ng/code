#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> b(n + 1);
  int k = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
    if (b[i] > i) {
      k = i;
    }
  }

  std::vector<std::vector<int>> v(n + 2);
  for (int i = 1; i <= n; i++) {
    v[b[i]].push_back(i);
  }
  int root = v[0].size() ? 0 : n + 1;
  std::vector<int> q = {root};
  for (int i = 0; i < (int)q.size(); i++) {
    int x = q[i];
    sort(v[x].begin(), v[x].end(),
         [&](int t1, int t2) { return v[t1].size() < v[t2].size(); });
    for (auto &e : v[x]) {
      q.push_back(e);
    }
  }

  std::cout << k << '\n';
  for (int i = 1; i < (int)q.size(); i++) {
    std::cout << q[i] << " \n"[i == (int)q.size() - 1];
  }
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
