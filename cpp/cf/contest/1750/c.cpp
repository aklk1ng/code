#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::string a, b;
  std::cin >> a >> b;
  a = '$' + a;
  b = '$' + b;
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    if (a[i] != char('1' - b[i] + '0')) {
      ok = false;
      break;
    }
  }
  ok = ok || (a == b);
  if (!ok) {
    std::cout << "NO\n";
    return;
  }

  std::vector<std::pair<int, int>> v;
  if (a[1] != b[1]) {
    v.push_back({1, n});
    a = b;
  }
  std::vector<int> cnt(n + 1);
  for (int i = 1; i <= n; i++) {
    if (a[i] == '1') {
      if (i == 1) {
        v.push_back({1, n});
        v.push_back({2, n});
      } else {
        cnt[i]++;
        cnt[i - 1]++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (cnt[i] % 2) {
      v.push_back({1, i});
    }
  }

  std::cout << "YES\n" << v.size() << '\n';
  for (auto &[x, y] : v) {
    std::cout << x << ' ' << y << '\n';
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
