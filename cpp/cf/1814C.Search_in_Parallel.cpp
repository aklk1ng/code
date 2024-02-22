#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> s(2);
  for (int i = 0; i < 2; i++) {
    std::cin >> s[i];
  }
  std::vector<std::pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i].first;
    a[i].second = i + 1;
  }

  std::sort(a.begin(), a.end());
  std::reverse(a.begin(), a.end());
  std::vector<std::vector<int>> l(2);
  for (int i = 0; i < n; i++) {
    int c1 = s[0] * (l[0].size() + 1);
    int c2 = s[1] * (l[1].size() + 1);
    if (c1 < c2) {
      l[0].push_back(a[i].second);
    } else {
      l[1].push_back(a[i].second);
    }
  }
  for (int i = 0; i < 2; i++) {
    std::cout << l[i].size();
    for (auto &e : l[i]) {
      std::cout << ' ' << e;
    }
    std::cout << '\n';
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
