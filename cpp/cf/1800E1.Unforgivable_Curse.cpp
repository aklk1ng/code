#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::string s, t;
  std::cin >> s >> t;
  auto eval = [&]() {
    std::set<std::string> w;
    std::queue<std::string> q;
    q.push(s);
    w.insert(s);

    auto add = [&](std::string &tmp, int i, int j) {
      if (i >= 0 && i < j && j < n) {
        std::swap(tmp[i], tmp[j]);
        if (!w.count(tmp)) {
          w.insert(tmp);
          q.push(tmp);
        }
        std::swap(tmp[i], tmp[j]);
      }
    };

    while (!q.empty()) {
      auto tmp = q.front();
      q.pop();
      for (int i = 0; i < n; i++) {
        add(tmp, i, i + k);
        add(tmp, i, i + k + 1);
        add(tmp, i - k, i);
        add(tmp, i - k - 1, i);
      }
    }
    std::cout << (w.count(t) ? "YES" : "NO") << '\n';
  };
  if (n <= 5) {
    eval();
    return;
  }

  std::map<char, int> m;
  for (auto &c : s) {
    m[c]++;
  }
  for (auto &c : t) {
    m[c]--;
  }
  bool ok = true;
  for (auto &[c, x] : m) {
    ok &= x == 0;
  }
  std::cout << (ok ? "YES" : "NO") << '\n';
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
