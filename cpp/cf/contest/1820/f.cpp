#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n);
  for (int i = 0; i < n; i++) {
    int k;
    std::cin >> k;
    for (int j = 0; j < k; j++) {
      int x;
      std::cin >> x;
      a[i].push_back(x);
    }
  }

  std::unordered_map<int, int> lst;
  auto get = [&](int i) {
    if (!lst.count(i)) {
      return -1;
    } else {
      return lst[i];
    }
  };
  std::vector<bool> zero(n + 1);
  std::vector<int> pre(n + 1);
  zero[0] = true;
  int ops = -1;
  for (int i = 0; i < n; i++) {
    if (a[i].empty()) {
      zero[i + 1] = true;
      lst[0] = i;
    } else {
      int need = get(0);
      int new_ops = ops;
      for (auto &e : a[i]) {
        need = std::max(need, get(e));
        new_ops = std::max(new_ops, get(e));
        lst[e] = i;
      }
      if (need != -1) {
        int tmp = pre[need];
        if (ops < tmp) {
          zero[i + 1] = true;
        }
      }
      ops = new_ops;
    }
    if (zero[i + 1]) {
      pre[i + 1] = i + 1;
    } else {
      pre[i + 1] = pre[i];
    }
  }
  std::unordered_set<int> vis;
  std::vector<int> cnt(n + 1);
  int cur = 0;
  for (int i = n - 1; i >= 0; i--) {
    bool ok = true;
    if (a[i].empty()) {
      vis.insert(0);
    }
    for (auto &e : a[i]) {
      if (vis.count(e)) {
        ok = false;
        break;
      }
      vis.insert(e);
      cur++;
    }
    if (!ok) {
      break;
    }
    if (vis.count(0)) {
      cnt[i] = m;
    } else {
      cnt[i] = cur;
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    if (zero[i]) {
      ans = std::max(ans, cnt[i]);
    }
  }
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
